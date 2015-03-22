inspect = require 'SimpleServer/inspect'

local File = {
	printFileTable = function (filetable)
		for k, line in ipairs(filetable) do print(line) end
	end,
	getClassTable = function (filetable)
		local t = {}
			for i, line in ipairs(filetable) do
				if string.match(line, "public:") then b1 = 1 end
				if b1 then print("is public:", i, line) end
				if b1 and (
					string.match(line, "};") or
					string.match(line, "private:") or
					string.match(line, "protected:")
				) then b1 = nil end
			end
		return t
	end,
	getClassName = function (filetable)
		for k, line in ipairs(filetable) do
			-- local t, name = string.match(line, "class(%s.+)%s(%S+)[%s{:]?")
			-- if name ~= nil then
				-- print(line)
				-- return name
			-- elseif t then
			-- 	print(line)
			-- 	return t
			-- end
			local match, inherence
			if string.match(line, "class") then
				class, inherence = string.match(line, "class.-%s([%a:]+)%s[:{]%s?(.*)")
				if not class and not inherence then
					class = string.match(line, ".-(%a+)$")
				end
				-- print("MATCH\t"..line)
				if class then
					print("\t\t"..class)
					print("\t"..inherence)
					return class
				end
			end
		end
	end,
	get = function (filename)
		local file_table = {}
		for line in io.input(filename):lines() do
			if not string.match(line, "%s*//") then
				table.insert(file_table, line)
			end
		end
		return file_table
	end,
	new = function (self, filename)
		-- print("filename:", filename)
		local filetable = self.get(filename)
		-- self.printFileTable(filetable)
		local ClassName = self.getClassName(filetable)
		-- print("getClassName:", ClassName)
		if not ClassName then return end
		if self[ClassName] then print("Warning: ", ClassName.." is already declared") end
		self[ClassName] = self.getClassTable(filetable)
	end
}

function grep_class_name(line)
	print("class", line)
	local a, b
	local t = {}
	a, b = string.match(line, "class%s+(.+)%s+:%s+(.+)%s")

	if not a then a = string.match(line, "(.+)") end

	if a then
		table.insert(t, string.match(line, a))
	end
	if b then
		table.insert(t, string.match(line, b))
	end

	local c
	c = string.match(line, "(.+)%s")
	print("c: <"..c..">")
	return t
end

function grep_file(filetable)
	local b1
	local c = {}

	local file = {}
	for k, line in ipairs(filetable) do
		if not b1 and string.match(line, "class%s([A-z]+)[%s{]?") then
			table.insert(file, grep_class_name(line))
			b1 = 1
		elseif string.match(line, "(%a+)%s(%a+)") then
			-- print("content", line)
		end
	-- print(line)
	end
	return file
end

-- for k,file in ipairs(arg) do
-- 	print("#### #### #### #### ####")
-- 	print(inspect(grep_file(from_file(file))))
-- 	print("")
-- end
for k,file in ipairs(arg) do
	print("#### #### #### #### #### #### ####")
	File:new(file)
	print("")
end

print(inspect(File))
