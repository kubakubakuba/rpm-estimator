#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "process.hh"
#include "regression.hh"

int main(){
	int NUM_IMG = 20;
	std::vector<float> fit_param;

	for (int i = 1; i <= 19; ++i) {
		std::ostringstream oss;
		oss << "img/frame" << std::setw(4) << std::setfill('0') << i << ".png";
		std::string filename = oss.str();
		std::cout << filename.c_str() << std::endl;
		
		Image img(filename.c_str());
		std::vector<Image> imgs = process(img);
		Image mask_w = imgs[0];
		Image mask_b = imgs[1];
		std::pair<std::vector<int>,std::vector<int>> pixels = get_pixels(mask_w, 100);

		Regression reg;
		reg.takeInput(pixels.first.size(), pixels);
		reg.PrintBestFittingLine();

		fit_param.push_back(reg.coeff);
	}

	std::vector<double> angles;

	for(int i = 0; i < fit_param.size() + 1; ++i){
		double m1 = fit_param[i];
		double m2 = fit_param[i + 1];

		double val = (m1 - m2) / (1 + m1*m2);

		double res = atan(val) * (180.0 / M_PI);

		std::cout << "angle: " << res << std::endl;

		angles.push_back(res);
	}

	// std::vector<int> xi;
	// std::vector<int> yi;

	// xi.push_back(1);
	// xi.push_back(2);
	// xi.push_back(3);

	// yi.push_back(2);
	// yi.push_back(3);
	// yi.push_back(4);


	// pixels = std::make_pair(xi, yi);
}