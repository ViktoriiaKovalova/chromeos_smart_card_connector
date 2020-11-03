// Copyright 2020 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_SMART_CARD_COMMON_GLOBAL_CONTEXT_H_
#define GOOGLE_SMART_CARD_COMMON_GLOBAL_CONTEXT_H_

#include <google_smart_card_common/value.h>

namespace google_smart_card {

// Global context is an interface that abstracts away webport-specific
// operations.
//
// The implementation of this class is required to be thread-safe.
class GlobalContext {
 public:
  virtual ~GlobalContext() = default;

  // Sends the given message to the JavaScript side. Returns whether the message
  // was sent successfully (note that the status doesn't tell anything about the
  // result of the message handling on the JS side).
  virtual bool PostMessageToJs(const Value& message) = 0;

  // Returns whether the current thread is the main event loop thread. Is
  // intended to be used to avoid blocking/deadlocking the main thread.
  virtual bool IsMainEventLoopThread() const = 0;

  // Disables communication with the JavaScript side. All calls to
  // `PostMessageToJs()` after this point will return `false`.
  virtual void DisableJsCommunication() = 0;
};

}  // namespace google_smart_card

#endif  // GOOGLE_SMART_CARD_COMMON_GLOBAL_CONTEXT_H_
