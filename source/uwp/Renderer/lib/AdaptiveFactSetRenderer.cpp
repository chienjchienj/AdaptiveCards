#include "pch.h"

#include "AdaptiveElementParserRegistration.h"
#include "AdaptiveFactSet.h"
#include "AdaptiveFactSetRenderer.h"
#include "enums.h"
#include "Util.h"
#include "XamlBuilder.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveNamespace;
using namespace ABI::Windows::Foundation;

namespace AdaptiveNamespace
{
    HRESULT AdaptiveFactSetRenderer::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    }
    CATCH_RETURN;

    HRESULT AdaptiveFactSetRenderer::Render(_In_ IAdaptiveCardElement* cardElement,
                                            _In_ IAdaptiveRenderContext* renderContext,
                                            _In_ IAdaptiveRenderArgs* renderArgs,
                                            _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result) noexcept try
    {
        return XamlBuilder::BuildFactSet(cardElement, renderContext, renderArgs, result);
    }
    CATCH_RETURN;

    HRESULT AdaptiveFactSetRenderer::FromJson(
        _In_ ABI::Windows::Data::Json::IJsonObject* jsonObject,
        _In_ ABI::AdaptiveNamespace::IAdaptiveElementParserRegistration* elementParserRegistration,
        _In_ ABI::AdaptiveNamespace::IAdaptiveActionParserRegistration* actionParserRegistration,
        _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>* adaptiveWarnings,
        _COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCardElement** element) noexcept try
    {
        return AdaptiveNamespace::FromJson<AdaptiveNamespace::AdaptiveFactSet, AdaptiveSharedNamespace::FactSet, AdaptiveSharedNamespace::FactSetParser>(
            jsonObject, elementParserRegistration, actionParserRegistration, adaptiveWarnings, element);
    }
    CATCH_RETURN;
}
