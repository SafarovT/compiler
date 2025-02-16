#pragma once
#include "../token/Token.h"

#include <string>
#include <unordered_map>

const std::unordered_map<std::string, TokenType> RESERVED_WORDS = {
	{ "mod", TokenType::OP_MOD },
	{ "div", TokenType::OP_DIV },
	{ "and", TokenType::OP_AND },
	{ "or", TokenType::OP_OR },
	{ "not", TokenType::OP_NOT },
	{ "true", TokenType::TRUE },
	{ "false", TokenType::FALSE },
};

inline const Token CheckReserved(Token const& token)
{
	const auto it = RESERVED_WORDS.find(token.value);
	return it == RESERVED_WORDS.end()
		? token
		: Token{
			.type = it->second,
			.value = token.value,
			.pos = token.pos,
			.error = token.error,
		};
}