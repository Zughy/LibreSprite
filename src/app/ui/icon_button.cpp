// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "app/ui/icon_button.h"

#include "app/ui/skin/skin_theme.h"
#include "she/surface.h"
#include "ui/events/paint_event.h"
#include "ui/events/size_hint_event.h"
#include "ui/message.h"
#include "ui/system.h"

namespace app {

using namespace ui;
using namespace app::skin;

IconButton::IconButton(she::Surface* icon)
  : Button("")
  , m_icon(icon)
{
  setBgColor(SkinTheme::instance()->colors.menuitemNormalFace());
}

void IconButton::onSizeHint(SizeHintEvent& ev)
{
  ev.setSizeHint(
    gfx::Size(m_icon->width(),
              m_icon->height()) + 4*guiscale());
}

void IconButton::onPaint(PaintEvent& ev)
{
  SkinTheme* theme = SkinTheme::instance();
  Graphics* g = ev.graphics();
  gfx::Color fg, bg;

  if (isSelected()) {
    fg = theme->colors.menuitemHighlightText();
    bg = theme->colors.menuitemHighlightFace();
  }
  else if (isEnabled() && hasMouseOver()) {
    fg = theme->colors.menuitemHotText();
    bg = theme->colors.menuitemHotFace();
  }
  else {
    fg = theme->colors.menuitemNormalText();
    bg = bgColor();
  }

  g->fillRect(bg, g->getClipBounds());

  gfx::Rect bounds = clientBounds();
  g->drawColoredRgbaSurface(
    m_icon, fg,
    bounds.x+bounds.w/2-m_icon->width()/2,
    bounds.y+bounds.h/2-m_icon->height()/2);
}

} // namespace app
