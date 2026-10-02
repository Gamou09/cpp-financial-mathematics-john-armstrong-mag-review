//
//  histogramChart.hpp
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 02/10/2026.
//

#ifndef histogramChart_hpp
#define histogramChart_hpp

#include <string>
#include <vector>

// Save a histogram as an HTML file.
void hist(const std::string& filename,
          const std::vector<double>& values,
          int nBins = 20);

#endif /* histogramChart_hpp */
