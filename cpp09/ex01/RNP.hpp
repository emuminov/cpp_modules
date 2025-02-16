#ifndef RNP_HPP
#define RNP_HPP
#include <stack>
#include <string>
class RNP {
	public:
		RNP();
		RNP(const RNP& rnp);
		RNP& operator=(const RNP& rnp);
		~RNP();

		int solve(const std::string& input);
	private:
		enum e_status {
			ok,
			error,
		};
		static const std::string s_valid_token_chars;
		std::stack<char> m_data;

		enum e_status _parse_input(const std::string& input);
		enum e_status _resolve_equation();
		bool _is_valid_token(const std::string& str) const;

};
#endif
