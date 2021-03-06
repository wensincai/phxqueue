/*
Tencent is pleased to support the open source community by making PhxQueue available.
Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

<https://opensource.org/licenses/BSD-3-Clause>

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
*/



/* phxrpc_store_dispatcher.h

 Generated by phxrpc_pb2service from store.proto

 Please DO NOT edit unless you know exactly what you are doing.

*/

#include "phxrpc_store_dispatcher.h"

#include <errno.h>

#include "phxrpc/file.h"
#include "phxrpc/http.h"

#include "phxrpc_store_service.h"
#include "store.pb.h"


StoreDispatcher::StoreDispatcher(StoreService &service, phxrpc::DispatcherArgs_t *dispatcher_args)
        : service_(service), dispatcher_args_(dispatcher_args) {}

StoreDispatcher::~StoreDispatcher() {}

const phxrpc::HttpDispatcher<StoreDispatcher>::URIFuncMap &
StoreDispatcher::GetURIFuncMap() {
    static phxrpc::HttpDispatcher<StoreDispatcher>::URIFuncMap uri_func_map = {
        {"/phxqueue_phxrpc.store/PhxEcho", &StoreDispatcher::PhxEcho},
        {"/phxqueue_phxrpc.store/Add", &StoreDispatcher::Add},
        {"/phxqueue_phxrpc.store/Get", &StoreDispatcher::Get}};
    return uri_func_map;
}

int StoreDispatcher::PhxEcho(const phxrpc::HttpRequest &req,
                             phxrpc::HttpResponse *const resp) {
    dispatcher_args_->server_monitor->SvrCall(-1, "PhxEcho", 1);

    int ret{0};

    google::protobuf::StringValue req_pb;
    google::protobuf::StringValue resp_pb;

    // unpack request
    {
        if (!req_pb.ParseFromString(req.GetContent())) {
            phxrpc::log(LOG_ERR, "ERROR: FromBuffer fail size %zu ip %s",
                        req.GetContent().size(), req.GetClientIP());
            return -EINVAL;
        }
    }

    // logic process
    {
        if (0 == ret) ret = service_.PhxEcho(req_pb, &resp_pb);
    }

    // pack response
    {
        if (!resp_pb.SerializeToString(&(resp->GetContent()))) {
            phxrpc::log(LOG_ERR, "ERROR: ToBuffer fail ip %s",
                        req.GetClientIP());
            return -ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: PhxEcho = %d", ret);

    return ret;
}

int StoreDispatcher::Add(const phxrpc::HttpRequest &req,
                         phxrpc::HttpResponse *const resp) {
    dispatcher_args_->server_monitor->SvrCall(1, "Add", 1);

    int ret{0};

    phxqueue::comm::proto::AddRequest req_pb;
    phxqueue::comm::proto::AddResponse resp_pb;

    // unpack request
    {
        if (!req_pb.ParseFromString(req.GetContent())) {
            phxrpc::log(LOG_ERR, "ERROR: FromBuffer fail size %zu ip %s",
                        req.GetContent().size(), req.GetClientIP());
            return -EINVAL;
        }
    }

    // logic process
    {
        if (0 == ret) ret = service_.Add(req_pb, &resp_pb);
    }

    // pack response
    {
        if (!resp_pb.SerializeToString(&(resp->GetContent()))) {
            phxrpc::log(LOG_ERR, "ERROR: ToBuffer fail ip %s",
                        req.GetClientIP());
            return -ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: Add = %d", ret);

    return ret;
}

int StoreDispatcher::Get(const phxrpc::HttpRequest &req,
                         phxrpc::HttpResponse *const resp) {
    dispatcher_args_->server_monitor->SvrCall(2, "Get", 1);

    int ret{0};

    phxqueue::comm::proto::GetRequest req_pb;
    phxqueue::comm::proto::GetResponse resp_pb;

    // unpack request
    {
        if (!req_pb.ParseFromString(req.GetContent())) {
            phxrpc::log(LOG_ERR, "ERROR: FromBuffer fail size %zu ip %s",
                        req.GetContent().size(), req.GetClientIP());
            return -EINVAL;
        }
    }

    // logic process
    {
        if (0 == ret) ret = service_.Get(req_pb, &resp_pb);
    }

    // pack response
    {
        if (!resp_pb.SerializeToString(&(resp->GetContent()))) {
            phxrpc::log(LOG_ERR, "ERROR: ToBuffer fail ip %s",
                        req.GetClientIP());
            return -ENOMEM;
        }
    }

    phxrpc::log(LOG_DEBUG, "RETN: Get = %d", ret);

    return ret;
}

