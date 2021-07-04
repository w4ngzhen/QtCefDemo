﻿#pragma once
// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "include/cef_app.h"

// Implement application-level callbacks for the browser process.
class SimpleApp : public CefApp, public CefBrowserProcessHandler
{
public:
    SimpleApp();

    // CefApp methods:
    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
    OVERRIDE
    {
        return this;
    }

    // CefBrowserProcessHandler methods:
    virtual void OnContextInitialized() OVERRIDE;

private:
    // Include the default reference counting implementation.
IMPLEMENT_REFCOUNTING(SimpleApp);
};
