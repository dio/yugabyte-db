// Copyright (c) YugaByte, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
// in compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied.  See the License for the specific language governing permissions and limitations
// under the License.
//

#ifndef YB_TABLET_OPERATIONS_WRITE_OPERATION_CONTEXT_H
#define YB_TABLET_OPERATIONS_WRITE_OPERATION_CONTEXT_H

#include "yb/common/hybrid_time.h"

#include "yb/tablet/tablet_fwd.h"

namespace yb {
namespace tablet {

class WriteOperationContext {
 public:
  // When operation completes, its callback is executed.
  virtual void Submit(std::unique_ptr<Operation> operation, int64_t term) = 0;
  virtual Result<HybridTime> ReportReadRestart() = 0;

  virtual ~WriteOperationContext() {}
};

}  // namespace tablet
}  // namespace yb

#endif  // YB_TABLET_OPERATIONS_WRITE_OPERATION_CONTEXT_H
