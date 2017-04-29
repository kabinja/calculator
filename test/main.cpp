void test(Tokenizer tokens, Parser parser, const std::string& expression, double expectation)
{
    tokens.tokenize(expression);
    parser.evaluate(tokens);

    double answer = ::atof(parser.answer().c_str());

    if(answer == expectation)
    {
        std::cout << expression << ": passed"  << std::endl;
    }
    else
    {
        std::cout << expression <<": failed, return " << answer << " instead of " << expectation << std::endl;
    }
}

int main(int argc, char *argv[])
{
    Tokenizer tokens;
    Parser parser;

    test(tokens, parser, "5 + 2", 7);
    test(tokens, parser, "5 - 2", 3);
    test(tokens, parser, "5 / 2", 2.5);
    test(tokens, parser, "5 * 2", 10);
    test(tokens, parser, "5 % 2", 1);

    return 0;
}
