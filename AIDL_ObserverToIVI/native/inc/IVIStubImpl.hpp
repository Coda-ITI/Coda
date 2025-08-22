#pragma once
#include <CommonAPI/CommonAPI.hpp>
#include "v1/coda/vehicle/IVIStubDefault.hpp"

namespace v1 {
namespace coda {
namespace vehicle {

class IVIStubImpl : public v1_0::coda::vehicle::IVIStubDefault {
public:
    IVIStubImpl();
    virtual ~IVIStubImpl();

    // Helper methods to trigger events
    void notifyThemeChange(const IVI::Theme &theme);

    // Method overrides
    virtual void requestTheme(const std::shared_ptr<CommonAPI::ClientId> _client, requestThemeReply_t _reply) override;
    virtual void changeTheme(const std::shared_ptr<CommonAPI::ClientId> _client, IVI::Theme _theme, changeThemeReply_t _reply) override;

private:
    IVI::Theme currentTheme_ = IVI::Theme::LIGHT;
};

} // namespace vehicle
} // namespace coda
} // namespace v1