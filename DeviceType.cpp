#include <DeviceType.h>


std::vector<std::string> getAttrNames(DeviceType type) {
	std::vector<std::string> result;
	if (type == CCD_Camera_Chameleon) {
		result.push_back(std::string("imageEncodedJpeg"));
		result.push_back(std::string("frameRate"));
		result.push_back(std::string("frameRateMin"));
		result.push_back(std::string("frameRateMax"));
		result.push_back(std::string("frameRateAuto"));
		result.push_back(std::string("frameRateOnOff"));
		result.push_back(std::string("exposure"));
		result.push_back(std::string("exposureMin"));
		result.push_back(std::string("exposureMax"));
		result.push_back(std::string("exposureAuto"));
		result.push_back(std::string("exposureOnOff"));
		result.push_back(std::string("exposureOnePush"));
		result.push_back(std::string("gamma"));
		result.push_back(std::string("gammaMin"));
		result.push_back(std::string("gammaMax"));
		result.push_back(std::string("gammaOnOff"));
		result.push_back(std::string("shutter"));
		result.push_back(std::string("shutterMin"));
		result.push_back(std::string("shutterMax"));
		result.push_back(std::string("shutterAuto"));
		result.push_back(std::string("shutterOnePush"));
		result.push_back(std::string("gain"));
		result.push_back(std::string("gainMin"));
		result.push_back(std::string("gainMax"));
		result.push_back(std::string("gainAuto"));
		result.push_back(std::string("gainOnePush"));
		result.push_back(std::string("imageWidth"));
		result.push_back(std::string("imageHeight"));
		result.push_back(std::string("quality"));
		result.push_back(std::string("scale"));
		result.push_back(std::string("x"));
		result.push_back(std::string("y"));
		result.push_back(std::string("a"));
		result.push_back(std::string("b"));
		result.push_back(std::string("phi"));
	} else if (CCD_Camera_BINP) {

	}
	return result;
}

std::vector<std::string> getSaveStateAttrNames(DeviceType type) {
	std::vector<std::string> result;
	if (type == CCD_Camera_Chameleon) {
		result.push_back(std::string("frameRate"));
		result.push_back(std::string("frameRateAuto"));
		result.push_back(std::string("frameRateOnOff"));
		result.push_back(std::string("exposure"));
		result.push_back(std::string("exposureAuto"));
		result.push_back(std::string("exposureOnOff"));
		result.push_back(std::string("exposureOnePush"));
		result.push_back(std::string("gamma"));
		result.push_back(std::string("gammaOnOff"));
		result.push_back(std::string("shutter"));
		result.push_back(std::string("shutterAuto"));
		result.push_back(std::string("shutterOnePush"));
		result.push_back(std::string("gain"));
		result.push_back(std::string("gainAuto"));
		result.push_back(std::string("gainOnePush"));
		result.push_back(std::string("quality"));
	} else if (CCD_Camera_BINP) {

	}
	return result;
}
