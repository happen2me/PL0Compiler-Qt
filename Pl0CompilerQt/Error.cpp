#include "Error.h"
#include <iostream>
#include <exception>
#include "Word.h"

Error::Error()
{
}


Error::~Error()
{
}

void Error::raise(int line, ErrorType errorType)
{
	std::cout << "\033[1;31m" << "Error " << errorType << " happened in line : " << line << "\033[0m" << std::endl;
}

void Error::raise(int line, ErrorType errorType, std::ostream& error_ostream)
{
	error_ostream << "Error " << errorType << " happened in line : " << line << std::endl;
	error_ostream << "\t";
	switch (errorType)
	{
	case Error::USE_EQUAL_INSTEAD_OF_ASSIGN:
		error_ostream << "use = instead of :=" << std::endl;
		break;
	case Error::EQUAL_MUST_BE_FOLLOWED_BY_NUMBER:
		error_ostream << "equal must be followed by number" << std::endl;
		break;
	case Error::IDENTIFIER_MUST_BE_FOLLOWED_BY_NUMBER:
		error_ostream << "identifier must be followed by number" << std::endl;
		break;
	case Error::SHOULD_BE_FOLLOWED_BY_IDENTIFIRE:
		error_ostream << "should be followed by identifier" << std::endl;
		break;
	case Error::MISSING_COMMA_OR_SEMICOLON:
		error_ostream << "missing , or ;" << std::endl;
		break;
	case Error::INCORRECT_SYMBOL_AFTER_PROC_DECLARATION:
		error_ostream << "Incorrect symbol after procedure declaration" << std::endl;
		break;
	case Error::EXPECT_STATEMENT:
		error_ostream << "expect statement" << std::endl;
		break;
	case Error::INCORECT_SYMBOL_AFTER_STATEMENT_IN_BLOCK:
		error_ostream << "incorrect symbol after statement in block" << std::endl;
		break;
	case Error::EXPECT_DOT_AT_END:
		error_ostream << "expect dot at end" << std::endl;
		break;
	case Error::MISSING_SEMICOLON:
		error_ostream << "missing ;" << std::endl;
		break;
	case Error::UNDECLARED_IDENTIFIER:
		error_ostream << "undeclared identifier" << std::endl;
		break;
	case Error::ASSIGNED_TO_CONST_OR_PROC:
		error_ostream << "can't assign to const or procedure" << std::endl;
		break;
	case Error::USE_ASSIGN_INSTEAD_OF_EQUAL:
		error_ostream << "use := insted of =" << std::endl;
		break;
	case Error::EXPECT_IDENTIFIER_AFTER_CALL:
		error_ostream << "expect identifier after call" << std::endl;
		break;
	case Error::CANNOT_CALL_VAR_OR_CONST:
		error_ostream << "cannot call var or const" << std::endl;
		break;
	case Error::EXPECT_THEN:
		error_ostream << "expect then" << std::endl;
		break;
	case Error::EXPECT_SEMICOLON_OR_END:
		error_ostream << "expect ; or end" << std::endl;
		break;
	case Error::EXPECT_DO:
		error_ostream << "expect do" << std::endl;
		break;
	case Error::INCORRECT_SYMBOL_AFTER_STATEMENT:
		error_ostream << "incorrect symbol after statement" << std::endl;
		break;
	case Error::EXPECT_RATIONAL_OPERATOR:
		error_ostream << "expect rational operator" << std::endl;
		break;
	case Error::EXPRESSION_CANNOT_CONTAIN_PROC:
		error_ostream << "expressio cannot contain procedure" << std::endl;
		break;
	case Error::MISSING_RIGHT_PARENTHESIS:
		error_ostream << "missing right parenthesis" << std::endl;
		break;
	case Error::INCORRECT_SYMBOL_AFTER_FACTOR:
		error_ostream << "incorrect symbol after factor" << std::endl;
		break;
	case Error::INCORECT_SYMBOL_LEADS_EXPRESSION:
		error_ostream << "incorrect symbol leads expression" << std::endl;
		break;
	case Error::EXCEED_MAX_LEVEL:
		error_ostream << "exceed max level" << std::endl;
		break;
	case Error::TOO_BIG_NUMBER:
		error_ostream << "number is too big" << std::endl;
		break;
	case Error::EXPECT_LEFT_PARENTHSIS:
		error_ostream << "expect left parenthsis" << std::endl;
		break;
	case Error::EXPECT_ASSIGN:
		error_ostream << "expect :=" << std::endl;
		break;
	case Error::EXPECT:
		break;
	case Error::UNEXPECTED:
		error_ostream << "unexpected symbol" << std::endl;
		break;
	default:
		break;
	}
}
