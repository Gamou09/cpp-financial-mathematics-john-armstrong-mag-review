//
// histogramChart.cpp
// MyLib
//

#include "histogramChart.hpp"

#include <algorithm>   // STL algorithms: min, max, minmax_element, max_element.
#include <cmath>       // std::isfinite.
#include <filesystem>  // Paths and directory creation (C++17 or later).
#include <fstream>     // std::ofstream: write the HTML file.
#include <iomanip>     // std::setprecision.
#include <numeric>     // std::accumulate: calculate the sample mean.
#include <stdexcept>   // std::invalid_argument, std::runtime_error.
#include <string>
#include <vector>

void hist(const std::string& filename,
          const std::vector<double>& values,
          int nBins) {

    if (values.empty() || nBins <= 0) {
        throw std::invalid_argument(
            "hist requires non-empty data and a positive bin count.");
    }

    for (double value : values) {
        if (!std::isfinite(value)) {
            throw std::invalid_argument("hist requires finite values.");
        }
    }

    // Calculate the observed mean without changing the simulation results.
    const double mean =
        std::accumulate(values.begin(), values.end(), 0.0)
        / static_cast<double>(values.size());

    // Determine the range and include zero as a reference.
    const auto limits = std::minmax_element(values.begin(), values.end());

    double lower = std::min(*limits.first, 0.0);
    double upper = std::max(*limits.second, 0.0);

    // Avoid a zero-width range when all results are zero.
    if (lower == upper) {
        lower -= 0.5;
        upper += 0.5;
    }

    // Add space so reference lines do not sit on the plot boundaries.
    const double padding = 0.05 * (upper - lower);
    lower -= padding;
    upper += padding;

    const double binWidth = (upper - lower) / nBins;
    std::vector<std::size_t> counts(nBins, 0);

    // Count the observations in each bin.
    for (double value : values) {
        const int bin = std::min(
            static_cast<int>((value - lower) / binWidth),
            nBins - 1);

        ++counts[bin];
    }

    const std::size_t maxCount =
        *std::max_element(counts.begin(), counts.end());

    // Create output folders when the filename contains a directory.
    const std::filesystem::path outputPath(filename);

    if (outputPath.has_parent_path()) {
        std::filesystem::create_directories(outputPath.parent_path());
    }

    std::ofstream file(outputPath);

    if (!file) {
        throw std::runtime_error(
            "Cannot create histogram file: " + filename);
    }

    file << std::setprecision(6);

    const double plotLeft = 70.0;
    const double plotTop = 40.0;
    const double plotWidth = 700.0;
    const double plotHeight = 300.0;
    const double plotBottom = plotTop + plotHeight;
    const double barWidth = plotWidth / nBins;

    file << "<!DOCTYPE html>\n"
         << "<html lang='en'>\n"
         << "<head>\n"
         << "<meta charset='utf-8'>\n"
         << "<meta name='viewport' content='width=device-width,initial-scale=1'>\n"
         << "<title>Delta hedging P&amp;L</title>\n"
         << "<style>\n"
         << "body{font-family:Arial,sans-serif;text-align:center;"
         << "margin:30px;color:#222;}\n"
         << "svg{width:100%;max-width:900px;}\n"
         << "</style>\n"
         << "</head>\n"
         << "<body>\n"
         << "<h2>Delta hedging P&amp;L</h2>\n"
         << "<p>" << values.size() << " simulations | "
         << nBins << " bins</p>\n"
         << "<p>Sample mean P&amp;L: <strong>"
         << mean << "</strong></p>\n"
         << "<p>Black dashed line: zero | "
         << "<span style='color:#c62828'>Red dashed line: sample mean</span>"
         << "</p>\n"
         << "<svg viewBox='0 0 840 420' "
         << "role='img' aria-label='Histogram of delta hedging profit and loss'>\n";

    // Draw histogram bars with hover labels.
    for (int i = 0; i < nBins; ++i) {
        const double height =
            plotHeight * static_cast<double>(counts[i])
            / static_cast<double>(maxCount);

        const double x = plotLeft + i * barWidth;
        const double y = plotBottom - height;

        file << "<rect x='" << x
             << "' y='" << y
             << "' width='" << barWidth
             << "' height='" << height
             << "' fill='steelblue' stroke='white'>\n"
             << "<title>P&amp;L: " << lower + i * binWidth
             << " to " << lower + (i + 1) * binWidth
             << " | Count: " << counts[i]
             << "</title>\n"
             << "</rect>\n";
    }

    // Draw reference lines after the bars so they remain visible.
    const double zeroX =
        plotLeft + (0.0 - lower) / (upper - lower) * plotWidth;

    const double meanX =
        plotLeft + (mean - lower) / (upper - lower) * plotWidth;

    file << "<line x1='" << zeroX << "' y1='" << plotTop
         << "' x2='" << zeroX << "' y2='" << plotBottom
         << "' stroke='black' stroke-width='2' stroke-dasharray='6,4'>"
         << "<title>Zero P&amp;L</title></line>\n";

    file << "<line x1='" << meanX << "' y1='" << plotTop
         << "' x2='" << meanX << "' y2='" << plotBottom
         << "' stroke='#c62828' stroke-width='2' stroke-dasharray='3,3'>"
         << "<title>Sample mean: " << mean << "</title></line>\n";

    // Axes.
    file << "<line x1='" << plotLeft << "' y1='" << plotBottom
         << "' x2='" << plotLeft + plotWidth << "' y2='" << plotBottom
         << "' stroke='black'/>\n";

    file << "<line x1='" << plotLeft << "' y1='" << plotTop
         << "' x2='" << plotLeft << "' y2='" << plotBottom
         << "' stroke='black'/>\n";

    // Horizontal-axis ticks.
    for (int i = 0; i <= 4; ++i) {
        const double fraction = i / 4.0;
        const double x = plotLeft + fraction * plotWidth;
        const double value = lower + fraction * (upper - lower);

        file << "<line x1='" << x << "' y1='" << plotBottom
             << "' x2='" << x << "' y2='" << plotBottom + 5
             << "' stroke='black'/>\n"
             << "<text x='" << x << "' y='" << plotBottom + 25
             << "' text-anchor='middle' font-size='12'>"
             << value << "</text>\n";
    }

    // Vertical-axis labels.
    file << "<text x='" << plotLeft - 10
         << "' y='" << plotTop + 5
         << "' text-anchor='end' font-size='12'>"
         << maxCount << "</text>\n"
         << "<text x='" << plotLeft - 10
         << "' y='" << plotBottom
         << "' text-anchor='end' font-size='12'>0</text>\n";

    file << "<text x='420' y='400' text-anchor='middle'>P&amp;L</text>\n"
         << "<text transform='translate(20,190) rotate(-90)' "
         << "text-anchor='middle'>Frequency</text>\n"
         << "</svg>\n"
         << "<p>The mean is calculated from the simulated results. "
         << "When it is close to zero, the reference lines nearly overlap.</p>\n"
         << "</body>\n"
         << "</html>\n";

    file.close();

    if (!file) {
        throw std::runtime_error(
            "Failed to write histogram file: " + filename);
    }
}
