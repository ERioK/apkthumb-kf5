#ifndef APKTHUMB_H
#define APKTHUMB_H
#include <kio/thumbcreator.h>

class ApkThumb: public ThumbCreator
{
public:
    ApkThumb ();
    virtual ~ApkThumb ();
    virtual bool create(const QString & path, int width, int height, QImage & img); 
};
#endif
