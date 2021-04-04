#ifndef DEVICETYPE_H
#define DEVICETYPE_H

#include <vector>
#include <string>

enum DeviceType {
    CCD_Camera_Chameleon,
    CCD_Camera_BINP
};

std::vector<std::string> getAttrNames(DeviceType type);
std::vector<std::string> getSaveStateAttrNames(DeviceType type);

#endif // DEVICETYPE_H

