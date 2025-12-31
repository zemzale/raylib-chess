local M = {}

M.run_game = function()
	vim.cmd("make")
	vim.cmd("!./bin/Debug/raylib-chess")
end

vim.keymap.set("n", "<leader>x", M.run_game, { noremap = true })
