/*
The MIT License (MIT)

Copyright (c) 2016 Marcus Spangenberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>

namespace TestUtils {

class TestFailure : public std::exception {
public:
	TestFailure(const char* inExpression, const char* inFunction, const int32_t inLine)
	{
		std::stringstream sstream;
		sstream << "\"" << inExpression << "\" - " << inFunction << ":" << inLine;
		infoString = sstream.str();
	}
	const std::string& getInfo() const {
		return infoString;
	}
private:
	std::string infoString;
};

class ScopedFunctionTrace {
public:
	ScopedFunctionTrace(const char* inFunctionName)
		: functionName(inFunctionName)
	{
		std::cout << "-- " << functionName << " begin" << std::endl;
	}
	~ScopedFunctionTrace() {
		std::cout << "   " << functionName << " end" << std::endl;
	}
private:
	std::string functionName;
};

} // namespace TestUtils

#define TEST_ENTER TestUtils::ScopedFunctionTrace testUtilsScopedFunctionTrace(__FUNCTION__);
#define TEST_VERIFY(x) if ((x) == false) {throw TestUtils::TestFailure(#x, __FUNCTION__, __LINE__); }
