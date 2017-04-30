void test(Tokenizer tokens, Parser parser, const std::string& expression, double expectation)
{
    tokens.tokenize(expression);
    parser.evaluate(tokens);

    double answer = ::atof(parser.answer().c_str());

    bool test = false;
    if(std::isnan(expectation))
        test = std::isnan(answer);
    else
        test = answer == expectation;

    if(test)
        std::cout << expression << " = " << answer << ": passed"  << std::endl;
    else
        std::cout << expression <<": failed, returns " << answer << " instead of " << expectation << std::endl;
}

int main(int argc, char *argv[])
{
    Tokenizer tokens;
    Parser parser;

    test(tokens, parser, "5 + 2.5", 7.5);
    test(tokens, parser, "5 - 2.5", 2.5);
    test(tokens, parser, "5 / 2.5", 2);
    test(tokens, parser, "5 * 2", 10);
    test(tokens, parser, "5 % 2", 1);
    test(tokens, parser, "power(5,2)", 25);
		test(tokens, parser, "sqrt(25)", 5);
    test(tokens, parser, "-5", -5);
    test(tokens, parser, "5 + 4 / 2", 7);
    test(tokens, parser, "(5 + 4) / 2", 4.5);
    test(tokens, parser, "1/0", std::numeric_limits<double>::infinity());
    test(tokens, parser, "5.1 % 2", std::nan("1"));
    test(tokens, parser, "power(5+2, 10/5)", 49);
    test(tokens, parser, "((((5))))+(((((6)))))", 11);
    test(tokens, parser, "5+-5", 0);
    test(tokens, parser, "power(5)", std::nan("1"));
		test(tokens, parser, "sqrt(25,2)", std::nan("1"));
    test(tokens, parser, "5++5", std::nan("1"));
    test(tokens, parser, "5-+5", std::nan("1"));
    test(tokens, parser, "5-/5", std::nan("1"));
    test(tokens, parser, "5-*5", std::nan("1"));
    test(tokens, parser, "5-((5)", std::nan("1"));

    return 0;
}
