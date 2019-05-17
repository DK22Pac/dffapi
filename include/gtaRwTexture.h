//
// dffapi
// https://github.com/DK22Pac/dffapi
//
#pragma once
#include "gtaRwTypes.h"
#include "gtaRwStream.h"
#include "gtaRwString.h"
#include "gtaRwAnisot.h"
#include "gtaRwSkyMipmap.h"
#include "gtaRwUnknownExtension.h"

typedef struct gtaRwTexture gtaRwTexture;

struct gtaRwTexture {
    gtaRwUInt8 filtering;
    gtaRwUInt8 uAddressing : 4;
    gtaRwUInt8 vAddressing : 4;
    gtaRwUInt8 generateMipMaps : 1;
    gtaRwUInt8 padding;
    gtaRwString name;
    gtaRwString maskName;

    // extensions

    gtaRwTextureSkyMipmap skyMipmap;
    gtaRwTextureAnisot anisot;

    gtaRwUnknownExtension *unknownExtensions;
    gtaRwUInt32 numUnknownExtensions;
};

void gtaRwTextureInit(gtaRwTexture *texObj, gtaRwTextureFilterMode filtering, gtaRwTextureAddressMode uAddressing, gtaRwTextureAddressMode vAddressing, gtaRwUInt8 generateMipMaps, gtaRwChar const *name, gtaRwChar const *maskName);
gtaRwBool gtaRwTextureRead(gtaRwTexture *texObj, gtaRwStream *stream);
gtaRwBool gtaRwTextureWrite(gtaRwTexture *texObj, gtaRwStream *stream);
gtaRwUInt32 gtaRwTextureSize(gtaRwTexture *texObj);
void gtaRwTextureDestroy(gtaRwTexture *texObj);
