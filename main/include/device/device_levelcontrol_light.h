#pragma once
#ifndef _DEVICE_LEVELCONTROL_LIGHT_H_
#define _DEVICE_LEVELCONTROL_LIGHT_H_

#include "device.h"

class CDeviceLevelControlLight : public CDevice
{
public:
    CDeviceLevelControlLight();

    bool matter_add_endpoint() override;
    bool matter_init_endpoint() override;
    void matter_on_change_attribute_value(
        esp_matter::attribute::callback_type_t type,
        uint32_t cluster_id,
        uint32_t attribute_id,
        esp_matter_attr_val_t *value
    ) override;
    void matter_update_all_attribute_values() override;

public:
    void toggle_state_action() override;

private:
    bool m_matter_update_by_client_clus_onoff_attr_onoff;
    bool m_matter_update_by_client_clus_levelcontrol_attr_currentlevel;

    void matter_update_clus_onoff_attr_onoff();
    void matter_update_clus_levelcontrol_attr_currentlevel();
};

#endif