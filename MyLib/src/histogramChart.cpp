//
//  histogramChart.cpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 02/10/2026.
//

#include "histogramChart.hpp"

#include <algorithm>  // std::minmax_element, std::max_element, std::min.
#include <cmath>      // std::isfinite.
#include <fstream>    // std::ofstream: write files.
#include <stdexcept>  // std::invalid_argument, std::runtime_error.
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

    // Determine the range covered by the histogram.
    const auto limits = std::minmax_element(values.begin(), values.end());
    double lower = *limits.first;
    double upper = *limits.second;

    // Give identical values a visible range.
    if (lower == upper) {
        lower -= 0.5;
        upper += 0.5;
    }

    const double binWidth = (upper - lower) / nBins;
    std::vector<int> counts(nBins, 0);

    // Count observations in each bin.
    for (double value : values) {
        // The maximum value belongs in the final bin.
        const int bin = std::min(
            static_cast<int>((value - lower) / binWidth),
            nBins - 1);

        ++counts[bin];
    }

    const int maxCount = *std::max_element(counts.begin(), counts.end());

    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot create histogram file: " + filename);
    }

    // Draw the bars using SVG inside an HTML document.
    const double plotWidth = 700.0;
    const double plotHeight = 300.0;
    const double barWidth = plotWidth / nBins;

    file << "<!DOCTYPE html>\n"
         << "<html><head><meta charset='utf-8'>"
         << "<title>Delta hedging P&amp;L</title></head>\n"
         << "<body style='font-family:Arial;text-align:center'>\n"
         << "<h2>Delta hedging P&amp;L</h2>\n"
         << "<p>" << values.size() << " simulations | "
         << nBins << " bins</p>\n"
         << "<svg viewBox='0 0 800 400' style='width:100%;max-width:900px'>\n"
         << "<line x1='50' y1='330' x2='750' y2='330' stroke='black'/>\n"
         << "<line x1='50' y1='30' x2='50' y2='330' stroke='black'/>\n";

    for (int i = 0; i < nBins; ++i) {
        const double height = plotHeight * counts[i] / maxCount;
        const double x = 50.0 + i * barWidth;
        const double y = 330.0 - height;

        file << "<rect x='" << x << "' y='" << y
             << "' width='" << barWidth << "' height='" << height
             << "' fill='steelblue' stroke='white'>"
             << "<title>Bin: " << lower + i * binWidth
             << " to " << lower + (i + 1) * binWidth
             << " | Count: " << counts[i]
             << "</title></rect>\n";
    }

    file << "<text x='45' y='25' text-anchor='end'>"
         << maxCount << "</text>\n"
         << "<text x='50' y='355'>" << lower << "</text>\n"
         << "<text x='750' y='355' text-anchor='end'>"
         << upper << "</text>\n"
         << "<text x='400' y='385' text-anchor='middle'>P&amp;L</text>\n"
         << "</svg></body></html>\n";

    file.close();
    if (!file) {
        throw std::runtime_error("Failed to write histogram file: " + filename);
    }
}
