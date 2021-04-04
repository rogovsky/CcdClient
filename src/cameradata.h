#ifndef CAMERADATA
#define CAMERADATA

#include <vector>
#include <jpeglib.h>

class AbstractCameraData
{

};

class ChameleonCameraData : public AbstractCameraData
{
public:
    int quality;
    std::vector<unsigned char> encodedImageJpeg;
    std::vector<unsigned char> image;
    int width, height;
    double frameRate;
    double exposure;
    double gain;
    double gamma;
    double shutter;
    bool frameRateAuto;
    bool frameRateOnOff;
    bool exposureAuto;
    bool exposureOnOff;
    bool exposureOnePush;
    bool gammaOnOff;
    bool gainAuto;
    bool gainOnePush;
    bool shutterAuto;
    bool shutterOnePush;

    void decode()
    {
        struct jpeg_decompress_struct cinfo;
        struct jpeg_error_mgr jerr;
        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_decompress(&cinfo);
        jpeg_mem_src(&cinfo, encodedImageJpeg.data(), encodedImageJpeg.size());
        jpeg_read_header(&cinfo, TRUE);
        jpeg_start_decompress(&cinfo);
        width = cinfo.output_width;
        height = cinfo.output_height;
        pixel_size = cinfo.output_components;
        int size = width * height * pixel_size;
        unsigned char *buffer = new unsigned char[size];
        int row_stride = cinfo.output_width * cinfo.output_components;
        while (cinfo.output_scanline < cinfo.output_height)
        {
            unsigned char *buffer_array[1];
            buffer_array[0] = buffer + (cinfo.output_scanline) * row_stride;
            jpeg_read_scanlines(&cinfo, buffer_array, 1);
        }
        jpeg_finish_decompress(&cinfo);
        jpeg_destroy_decompress(&cinfo);
        image.insert(image.begin(), buffer, buffer + size);
        delete[] buffer;
    }
};

#endif // CAMERADATA

