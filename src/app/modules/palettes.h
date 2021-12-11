// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#pragma once

#include <memory>
#include <string>

namespace doc {
  class Palette;
}

namespace app {
  using namespace doc;

  int init_module_palette();
  void exit_module_palette();

  // Loads the default palette or creates it. Also it migrates the
  // palette if the palette format changes, etc. The "userDefined"
  // parameter can be a default palette name specified in the command
  // line.
  void load_default_palette(const std::string& userDefined);

  std::shared_ptr<Palette> get_default_palette();
  std::shared_ptr<Palette> get_current_palette();

  void set_default_palette(std::shared_ptr<Palette> palette);
  bool set_current_palette(std::shared_ptr<Palette> palette, bool forced);

  std::string get_preset_palette_filename(const std::string& preset,
                                          const std::string& dot_extension);
  std::string get_default_palette_preset_name();

} // namespace app
