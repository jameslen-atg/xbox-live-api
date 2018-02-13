﻿// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN

class xbox_web_socket_client : public std::enable_shared_from_this<xbox_web_socket_client>
{
public:
    xbox_web_socket_client();
    ~xbox_web_socket_client();

    virtual void connect(
        _In_ const std::shared_ptr<user_context>& userContext,
        _In_ const xsapi_internal_string& uri,
        _In_ const xsapi_internal_string& subProtocol,
        _In_ xbox::services::xbox_live_callback<HC_RESULT, uint32_t> callback
        );

    virtual void send(
        _In_ const xsapi_internal_string& message,
        _In_ xbox::services::xbox_live_callback<HC_RESULT, uint32_t> callback
        );

    virtual void close();

    virtual void set_received_handler(
        _In_ xbox_live_callback<xsapi_internal_string> handler
        );

    virtual void set_closed_handler(
        _In_ xbox_live_callback<HC_WEBSOCKET_CLOSE_STATUS> handler
        );

private:
    HC_WEBSOCKET_HANDLE m_websocket;

    xbox_live_callback<xsapi_internal_string> m_receiveHandler;
    xbox_live_callback<HC_WEBSOCKET_CLOSE_STATUS> m_closeHandler;

    static xsapi_internal_unordered_map<HC_WEBSOCKET_HANDLE, xbox_web_socket_client*> m_handleMap;
};

NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END
