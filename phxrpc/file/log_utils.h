/*
Tencent is pleased to support the open source community by making
PhxRPC available.
Copyright (C) 2016 THL A29 Limited, a Tencent company.
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may
not use this file except in compliance with the License. You may
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing
permissions and limitations under the License.

See the AUTHORS file for names of contributors.
*/

#pragma once

#include <syslog.h>

#include <cstdarg>


namespace phxrpc {


extern void openlog(const char *argv0, const char *log_dir, int priority);
extern void closelog();

extern void log(int priority, const char *format, ...) __attribute__((format(printf, 2, 3)));  
                                //按printf的格式检查参数，第二个参数为格式化字符串，从第三个参数开始检查

typedef void (*openlog_t)(const char *, const char *, int);  //连接syslogd
typedef void (*closelog_t)();  //关闭连接

typedef void (*vlog_t)(int, const char *, va_list);  //向syslogd写日志
extern void setvlog(vlog_t);

extern void setlog(openlog_t, closelog_t, vlog_t);  //设置三个函数指针


}  // namespace phxrpc

