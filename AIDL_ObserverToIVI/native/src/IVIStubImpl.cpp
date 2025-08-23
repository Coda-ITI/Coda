#include "IVIStubImpl.hpp"

namespace v1 {
namespace coda {
namespace vehicle {

IVIStubImpl::IVIStubImpl() 
{
    currentTheme_ = IVI::Theme::LIGHT;
}

IVIStubImpl::~IVIStubImpl() {}

void IVIStubImpl::notifyThemeChange(const IVI::Theme &theme) 
{
    if (theme.validate()) 
    {
        currentTheme_ = theme;
        fireNotifyThemeChangeEvent(theme);
    }
}

void IVIStubImpl::requestTheme(const std::shared_ptr<CommonAPI::ClientId> _client, requestThemeReply_t _reply) 
{
    (void)_client; 
    _reply(currentTheme_);
}

void IVIStubImpl::changeTheme(const std::shared_ptr<CommonAPI::ClientId> _client, IVI::Theme _theme, changeThemeReply_t _reply) 
{
    (void)_client; 
    
    if (_theme.validate()) 
    {
        currentTheme_ = _theme;
        fireNotifyThemeChangeEvent(_theme);
    }
    _reply();
}

} 
} 
} 