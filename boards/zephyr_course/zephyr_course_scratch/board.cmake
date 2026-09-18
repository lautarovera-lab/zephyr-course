# Copyright (c) 2026 Lautaro Vera
# SPDX-License-Identifier: Apache-2.0

board_runner_args(linkserver "--device=MCXN236:FRDM-MCXN236")
board_runner_args(jlink "--device=MCXN236" "--reset-after-load")

include(${ZEPHYR_BASE}/boards/common/linkserver.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
