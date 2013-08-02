// token.cpp
// by David Weinman
// 7/25/13 11:00p

#include "token.hpp"

// ---- prototypes

Token::Token(TokenType, char*);
TokenType Token::type();
char* Token::value();
Token Token::keyword();
Token Token::mkIdentTok(char *);
Token Token::mkIntLiteral(char *);
Token Token::mkFloatLiteral(char *);
Token Token::mkCharLiteral(char *);
char * Token::toString();
int main(int, char**);

// ---- def'ns

Token::Token(TokenType t, char * val) {

	type = t;
	value = val;
	if (t < TokenType::Eof) {
		reserved[t];
		token[t] = this;
	}	

}

TokenType Token::type() { return type; }

char* Token::value() { return value; }

int main() {



}


/* HEADER

struct Token {

	Token eofTok = Token(TokenType.Eof, "<<EOF>>");
	Token boolTok = Token(TokenType.Bool, "bool");
	Token charTok = Token(TokenType.Char, "char");
	Token elseTok = Token(TokenType.Else, "else");
	Token falseTok = Token(TokenType.False, "false");
	Token floatTok = Token(TokenType.Float, "float");
	Token ifTok = Token(TokenType.If, "if");
	Token intTok = Token(TokenType.Int, "int");
	Token mainTok = Token(TokenType.Main, "main");
	Token trueTok = Token(TokenType.True, "true");
	Token whileTok = Token(TokenType.While, "while");
	Token leftBraceTok = Token(TokenType.LeftBrace, "{");
	Token rightBraceTok = Token(TokenType.RightBrace, "}");
	Token leftBracketTok = Token(TokenType.LeftBracket, "[");
	Token rightBracketTok = Token(TokenType.RightBracket, "]");
	Token leftParenTok = Token(TokenType.LeftParen, "(");
	Token rightParenTok = Token(TokenType.RightParen, ")");
	Token semicolonTok = Token(TokenType.Semicolon, ";");
	Token commaTok = Token(TokenType.Comma, ",");
	Token assignTok = Token(TokenType.Assign, "=");
	Token eqeqTok = Token(TokenType.Equals, "==");
	Token ltTok = Token(TokenType.Less, "<");
	Token lteqTok = Token(TokenType.LessEqual, "<=");
	Token gtTok = Token(TokenType.Greater, ">");
	Token gteqTok = Token(TokenType.GreaterEqual, ">=");
	Token notTok = Token(TokenType.Not, "!");
	Token noteqTok = Token(TokenType.NotEqual, "!=");
	Token plusTok = Token(TokenType.Plus, "+");
	Token minusTok = Token(TokenType.Minus, "-");
	Token multiplyTok = Token(TokenType.Multiply, "*");
	Token divideTok = Token(TokenType.Divide, "/");
	Token andTok = Token(TokenType.And, "&&");
	Token orTok = Token(TokenType.Or, "||");
	Token returnTok = Token(TokenType.Return, "return");
	Token voidTok = Token(TokenType.Void, "void");

	TokenType type();
	char* value();

	private:
		int KEYWORDS = tokenType.Eof; // tokenType.Eof returns the
					      // integer value of where the
					      // Eof token is in the enum
		char * reserved; //= new string of size KEYWORDS
		Token[] token = Token[KEYWORDS];
		TokenType type;
		char * value;

};

enum TokenType {

	 Void, Bool, Char, Else, False, Float,
     If, Int, Main, True, While, Return,
     Eof, LeftBrace, RightBrace, LeftBracket, RightBracket,
     LeftParen, RightParen, Semicolon, Comma, Assign,
     Equals, Less, LessEqual, Greater, GreaterEqual,
     Not, NotEqual, Plus, Minus, Multiply,
     Divide, And, Or, Identifier, IntLiteral,
     FloatLiteral, CharLiteral
};


*/

/* OLD CODE / INSPIRATION (JAVA)

//
        David Weinman
        The Evergreen State College / Computability and the study of Formal Languages
        Sheryl Shulman and Neal Nelson

NOTES:
        Skeleton code provided by Allen B. Tucker & Robert E. Noonan from Programming Languages Principles and Paradigms 2.ed
//

public class Token {

    private static final int KEYWORDS = TokenType.Eof.ordinal();

    private static final String[] reserved = new String[KEYWORDS];
    private static Token[] token = new Token[KEYWORDS];

    public static final Token eofTok = new Token(TokenType.Eof, "<<EOF>>");
    public static final Token boolTok = new Token(TokenType.Bool, "bool");
    public static final Token charTok = new Token(TokenType.Char, "char");
    public static final Token elseTok = new Token(TokenType.Else, "else");
    public static final Token falseTok = new Token(TokenType.False, "false");
    public static final Token floatTok = new Token(TokenType.Float, "float");
    public static final Token ifTok = new Token(TokenType.If, "if");
    public static final Token intTok = new Token(TokenType.Int, "int");
    public static final Token mainTok = new Token(TokenType.Main, "main");
    public static final Token trueTok = new Token(TokenType.True, "true");
    public static final Token whileTok = new Token(TokenType.While, "while");
    public static final Token leftBraceTok = new Token(TokenType.LeftBrace, "{");
    public static final Token rightBraceTok = new Token(TokenType.RightBrace, "}");
    public static final Token leftBracketTok = new Token(TokenType.LeftBracket, "[");
    public static final Token rightBracketTok = new Token(TokenType.RightBracket, "]");
    public static final Token leftParenTok = new Token(TokenType.LeftParen, "(");
    public static final Token rightParenTok = new Token(TokenType.RightParen, ")");
    public static final Token semicolonTok = new Token(TokenType.Semicolon, ";");
    public static final Token commaTok = new Token(TokenType.Comma, ",");
    public static final Token assignTok = new Token(TokenType.Assign, "=");
    public static final Token eqeqTok = new Token(TokenType.Equals, "==");
    public static final Token ltTok = new Token(TokenType.Less, "<");
    public static final Token lteqTok = new Token(TokenType.LessEqual, "<=");
    public static final Token gtTok = new Token(TokenType.Greater, ">");
    public static final Token gteqTok = new Token(TokenType.GreaterEqual, ">=");
    public static final Token notTok = new Token(TokenType.Not, "!");
    public static final Token noteqTok = new Token(TokenType.NotEqual, "!=");
    public static final Token plusTok = new Token(TokenType.Plus, "+");
    public static final Token minusTok = new Token(TokenType.Minus, "-");
    public static final Token multiplyTok = new Token(TokenType.Multiply, "*");
    public static final Token divideTok = new Token(TokenType.Divide, "/");
    public static final Token andTok = new Token(TokenType.And, "&&");
    public static final Token orTok = new Token(TokenType.Or, "||");
    public static final Token returnTok = new Token(TokenType.Return, "return");
    public static final Token voidTok = new Token(TokenType.Void, "void");

    private TokenType type;
    private String value = "";

    private Token (TokenType t, String v) {
        type = t;
        value = v;
        if (t.compareTo(TokenType.Eof) < 0) {
            int ti = t.ordinal();
            reserved[ti] = v;
            token[ti] = this;
        }
    }

    public TokenType type( ) { return type; }

    public String value( ) { return value; }

    public static Token keyword  ( String name ) {
        char ch = name.charAt(0);
        
        if (ch >= 'A' && ch <= 'Z') return mkIdentTok(name);
        for (int i = 0; i < KEYWORDS; i++)
           if (name.equals(reserved[i])) return token[i];
        return mkIdentTok(name);
    } // keyword

    public static Token mkIdentTok (String name) {
        return new Token(TokenType.Identifier, name);
    }

    public static Token mkIntLiteral (String name) {
        return new Token(TokenType.IntLiteral, name);
    }

    public static Token mkFloatLiteral (String name) {
        return new Token(TokenType.FloatLiteral, name);
    }

    public static Token mkCharLiteral (String name) {
        return new Token(TokenType.CharLiteral, name);
    }

    public String toString ( ) {
        if (type.compareTo(TokenType.Identifier) < 0) return value;
        return type + "\t" + value;
    } // toString

    public static void main (String[] args) {
        System.out.println(eofTok.value);
        System.out.println(whileTok.value);
        System.out.println(returnTok.value);
        System.out.println(voidTok.value);
    }
} // Token


*/
