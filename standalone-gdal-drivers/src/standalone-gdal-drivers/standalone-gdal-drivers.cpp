#include <iostream>
#include <cstdlib>
#include <cstring>

#include <gdal/cpl_port.h>

#include "dbglog/dbglog.hpp"

#include "gdal-drivers/register.hpp"

// driver registration function
CPL_C_START
void GDALRegister_Melown(void) __attribute__ ((visibility("default")));

void GDALRegister_Melown(void)
{
    if (const auto *value = std::getenv("LOG_MASK")) {
        dbglog::set_mask(value);
    }
    if (const auto *value = std::getenv("LOG_FILE")) {
        dbglog::log_file(value);
    }
    if (const auto *value = std::getenv("LOG_CONSOLE")) {
        dbglog::log_console(std::strcmp(value, "1"));
    }

    gdal_drivers::registerAll();
}
CPL_C_END
