/*++

          ##     ## ######## ##     ## ########
          ##     ## ##       ##     ## ##     ##
          ##     ## ##       ##     ## ##     ##
          ######### ######   ##     ## ##     ##
          ##     ## ##        ##   ##  ##     ##
          ##     ## ##         ## ##   ##     ##
          ##     ## ########    ###    ########

            HackSys Extreme Vulnerable Driver

Author : Ashfaq Ansari
Contact: ashfaq[at]hacksys[dot]io
Website: https://hacksys.io/

Copyright (C) 2021-2023 HackSys Inc. All rights reserved.
Copyright (C) 2015-2020 Payatu Software Labs LLP. All rights reserved.

This program is free software: you can redistribute it and/or modify it under the terms of
the GNU General Public License as published by the Free Software Foundation, either version
3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

See the file 'LICENSE' for complete copying permission.

Module Name:
    UseAfterFreeNonPagedPool.h

Abstract:
    This module implements the data structures for
    use after free in NonPagedPool module.

--*/

#pragma once

#ifndef __USE_AFTER_FREE_NON_PAGED_POOL_H__
#define __USE_AFTER_FREE_NON_PAGED_POOL_H__

#include "Common.h"


//
// Structures
//

typedef struct _USE_AFTER_FREE_NON_PAGED_POOL
{
    FunctionPointer Callback;
    CHAR Buffer[0x54];
} USE_AFTER_FREE_NON_PAGED_POOL, *PUSE_AFTER_FREE_NON_PAGED_POOL;

typedef struct _FAKE_OBJECT_NON_PAGED_POOL
{
    CHAR Buffer[0x54 + sizeof(PVOID)];
} FAKE_OBJECT_NON_PAGED_POOL, *PFAKE_OBJECT_NON_PAGED_POOL;


//
// Function Definitions
//

VOID
UaFObjectCallbackNonPagedPool(
    VOID
);

NTSTATUS
UseUaFObjectNonPagedPool(
    VOID
);

NTSTATUS
FreeUaFObjectNonPagedPool(
    VOID
);

NTSTATUS
AllocateUaFObjectNonPagedPool(
    VOID
);

NTSTATUS
AllocateFakeObjectNonPagedPool(
    _In_ PFAKE_OBJECT_NON_PAGED_POOL UserFakeObject
);

#endif  // !__USE_AFTER_FREE_NON_PAGED_POOL_H__
