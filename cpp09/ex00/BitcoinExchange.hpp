#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <ctime>
#include <string>
class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& bc);
		BitcoinExchange& operator=(const BitcoinExchange& bc);
		~BitcoinExchange();

		void print_exchange_rate_from_input(const std::string& file_name);
	private:
		enum e_error {
			ok,
			database_access_error,
			input_access_error,
			empty_database,
		};
		static const std::string s_db_name;
		typedef std::map<std::string, double>::iterator iterator;
		typedef struct s_date {
			int year;
			int month;
			int day;
		} t_date;

		std::map<std::string, double> m_data;

		enum e_error _read_db();
		enum e_error _read_input(const std::string& file_name);
		t_date _str_to_date(const std::string& str);
};
#endif
