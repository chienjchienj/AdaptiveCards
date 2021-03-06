#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include <windows.foundation.h>
#include "Enums.h"

namespace AdaptiveNamespace
{
    class DECLSPEC_UUID("CDCCC115-7C53-4A04-9F5B-754BBC00C80E") AdaptiveActionElementBase : public IUnknown
    {
    public:
        InternalId GetInternalId() { return m_internalId; }

    protected:
        HRESULT InitializeBaseElement(const std::shared_ptr<AdaptiveSharedNamespace::BaseActionElement>& sharedModel);

        IFACEMETHODIMP get_ActionTypeString(_Outptr_ HSTRING* value);

        IFACEMETHODIMP get_Title(_Outptr_ HSTRING* title);
        IFACEMETHODIMP put_Title(_In_ HSTRING title);

        IFACEMETHODIMP get_Id(_Outptr_ HSTRING* id);
        IFACEMETHODIMP put_Id(_In_ HSTRING id);

        IFACEMETHODIMP get_IconUrl(_Outptr_ HSTRING* iconUrl);
        IFACEMETHODIMP put_IconUrl(_In_ HSTRING iconUrl);

        IFACEMETHODIMP get_Sentiment(_Outptr_ HSTRING* sentiment);
        IFACEMETHODIMP put_Sentiment(_In_ HSTRING sentiment);

        IFACEMETHODIMP get_AdditionalProperties(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result);
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value);

        IFACEMETHODIMP ToJson(_COM_Outptr_ ABI::Windows::Data::Json::IJsonObject** result);

        HRESULT SetSharedElementProperties(std::shared_ptr<AdaptiveSharedNamespace::BaseActionElement> sharedCardElement);

        virtual HRESULT GetSharedModel(std::shared_ptr<BaseActionElement>& sharedModel) = 0;

    private:
        Microsoft::WRL::Wrappers::HString m_id;
        Microsoft::WRL::Wrappers::HString m_title;
        Microsoft::WRL::Wrappers::HString m_iconUrl;
        Microsoft::WRL::Wrappers::HString m_sentiment;
        Microsoft::WRL::ComPtr<ABI::Windows::Data::Json::IJsonObject> m_additionalProperties;
        Microsoft::WRL::Wrappers::HString m_typeString;
        InternalId m_internalId;
    };
}
