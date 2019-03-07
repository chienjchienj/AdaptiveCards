#include "pch.h"

#include "AdaptiveElementParserRegistration.h"
#include "AdaptiveNumberInput.h"
#include "AdaptiveNumberInputRenderer.h"
#include "enums.h"
#include "Util.h"
#include "XamlBuilder.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespace;
using namespace ABI::Windows::Foundation;

namespace AdaptiveNamespace
{
    HRESULT AdaptiveNumberInputRenderer::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    }
    CATCH_RETURN;

    HRESULT AdaptiveNumberInputRenderer::Render(_In_ IAdaptiveCardElement* cardElement,
                                                _In_ IAdaptiveRenderContext* renderContext,
                                                _In_ IAdaptiveRenderArgs* renderArgs,
                                                _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result) noexcept try
    {
        return XamlBuilder::BuildNumberInput(cardElement, renderContext, renderArgs, result);
    }
    CATCH_RETURN;

    HRESULT AdaptiveNumberInputRenderer::FromJson(
        _In_ ABI::Windows::Data::Json::IJsonObject* jsonObject,
        _In_ ABI::AdaptiveNamespace::IAdaptiveElementParserRegistration* elementParserRegistration,
        _In_ ABI::AdaptiveNamespace::IAdaptiveActionParserRegistration* actionParserRegistration,
        _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>* adaptiveWarnings,
        _COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCardElement** element) noexcept try
    {
        return AdaptiveNamespace::FromJson<AdaptiveNamespace::AdaptiveNumberInput, AdaptiveSharedNamespace::NumberInput, AdaptiveSharedNamespace::NumberInputParser>(
            jsonObject, elementParserRegistration, actionParserRegistration, adaptiveWarnings, element);
    }
    CATCH_RETURN;
}
