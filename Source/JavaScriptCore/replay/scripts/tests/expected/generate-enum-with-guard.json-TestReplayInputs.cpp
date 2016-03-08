/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// DO NOT EDIT THIS FILE. It is automatically generated from generate-enum-with-guard.json
// by the script: JavaScriptCore/replay/scripts/CodeGeneratorReplayInputs.py

#include "config.h"
#include "generate-enum-with-guard.json-TestReplayInputs.h"

#if ENABLE(WEB_REPLAY)
#include "InternalNamespaceImplIncludeDummy.h"
#include <platform/ExternalNamespaceImplIncludeDummy.h>
#include <platform/PlatformWheelEvent.h>

namespace Test {
HandleWheelEvent::HandleWheelEvent(std::unique_ptr<PlatformWheelEvent> platformEvent)
    : EventLoopInput<HandleWheelEvent>()
    , m_platformEvent(WTF::move(platformEvent))
{
}

HandleWheelEvent::~HandleWheelEvent()
{
}
} // namespace Test

namespace JSC {
const AtomicString& InputTraits<Test::HandleWheelEvent>::type()
{
    static NeverDestroyed<const AtomicString> type("HandleWheelEvent", AtomicString::ConstructFromLiteral);
    return type;
}

void InputTraits<Test::HandleWheelEvent>::encode(EncodedValue& encodedValue, const Test::HandleWheelEvent& input)
{
    encodedValue.put<WebCore::PlatformWheelEvent>(ASCIILiteral("platformEvent"), input.platformEvent());
}

bool InputTraits<Test::HandleWheelEvent>::decode(EncodedValue& encodedValue, std::unique_ptr<Test::HandleWheelEvent>& input)
{
    std::unique_ptr<WebCore::PlatformWheelEvent> platformEvent;
    if (!encodedValue.get<WebCore::PlatformWheelEvent>(ASCIILiteral("platformEvent"), platformEvent))
        return false;

    input = std::make_unique<Test::HandleWheelEvent>(WTF::move(platformEvent));
    return true;
}
#if ENABLE(DUMMY_FEATURE)
EncodedValue EncodingTraits<WebCore::PlatformWheelEventPhase>::encodeValue(const WebCore::PlatformWheelEventPhase& enumValue)
{
    EncodedValue encodedValue = EncodedValue::createArray();
    if (enumValue & WebCore::PlatformWheelEventPhaseNone) {
        encodedValue.append<String>(ASCIILiteral("PlatformWheelEventPhaseNone"));
        if (enumValue == WebCore::PlatformWheelEventPhaseNone)
            return encodedValue;
    }
    return encodedValue;
}

bool EncodingTraits<WebCore::PlatformWheelEventPhase>::decodeValue(EncodedValue& encodedValue, WebCore::PlatformWheelEventPhase& enumValue)
{
    Vector<String> enumStrings;
    if (!EncodingTraits<Vector<String>>::decodeValue(encodedValue, enumStrings))
        return false;

    for (String enumString : enumStrings) {
        if (enumString == "PlatformWheelEventPhaseNone")
            enumValue = static_cast<WebCore::PlatformWheelEventPhase>(enumValue | WebCore::PlatformWheelEventPhaseNone);
    }

    return true;
}
#endif // ENABLE(DUMMY_FEATURE)
} // namespace JSC

#endif // ENABLE(WEB_REPLAY)