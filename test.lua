inspect = require 'SimpleServer/inspect'

function from_file(filename)
	local file_table = {}
	for line in io.input(filename):lines() do
		if not string.match(line, "%s*//") then
			table.insert(file_table, line)
		end
	end
	return file_table
end

function grep_class_name(line)
	print("class", line)
	local a, b
	local t = {}
	a, b = string.match(line, "(.+) : (.+)[%s{]?")
	if a then
		table.insert(t, string.match(line, a))
	end
	if b then
		table.insert(t, string.match(line, b))
	end
	return t
end

function grep_file(filetable)
	local b1
	local c = {}

	_Gname = {}
	for k, line in ipairs(filetable) do
		if not b1 and string.match(line, "class%s([A-z]+)[%s{]?") then
			table.insert(_Gname, grep_class_name(line))
			b1 = 1
		elseif string.match(line, "(%a+)%s(%a+)") then
			print("content", line)
		end
	-- print(line)
	end
end

for k,file in ipairs(arg) do
	print("#### #### #### #### ####")
	grep_file(from_file(file))
	print(inspect(_Gname))
	print("")
end

