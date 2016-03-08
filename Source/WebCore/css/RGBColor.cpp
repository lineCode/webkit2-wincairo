/*
 * Copyright (C) 2008, 2009 Google, Inc.  All rights reserved.
 * Copyright (C) 2009 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "RGBColor.h"
#include "CSSPrimitiveValue.h"

namespace WebCore {

PassRefPtr<RGBColor> RGBColor::create(unsigned rgbColor)
{
    return adoptRef(new RGBColor(rgbColor));
}

PassRefPtr<CSSPrimitiveValue> RGBColor::red()
{
    unsigned value = (m_rgbColor >> 16) & 0xFF;
    RefPtr<CSSPrimitiveValue> result = CSSPrimitiveValue::create(value, CSSPrimitiveValue::CSS_NUMBER);
    result->setCSSOMSafe();
    return result.release();
}

PassRefPtr<CSSPrimitiveValue> RGBColor::green()
{
    unsigned value = (m_rgbColor >> 8) & 0xFF;
    RefPtr<CSSPrimitiveValue> result = CSSPrimitiveValue::create(value, CSSPrimitiveValue::CSS_NUMBER);
    result->setCSSOMSafe();
    return result.release();
}

PassRefPtr<CSSPrimitiveValue> RGBColor::blue()
{
    unsigned value = m_rgbColor & 0xFF;
    RefPtr<CSSPrimitiveValue> result = CSSPrimitiveValue::create(value, CSSPrimitiveValue::CSS_NUMBER);
    result->setCSSOMSafe();
    return result.release();
}

PassRefPtr<CSSPrimitiveValue> RGBColor::alpha()
{
    float value = static_cast<float>((m_rgbColor >> 24) & 0xFF) / 0xFF;
    RefPtr<CSSPrimitiveValue> result = CSSPrimitiveValue::create(value, CSSPrimitiveValue::CSS_NUMBER);
    result->setCSSOMSafe();
    return result.release();
}

} // namespace WebCore
