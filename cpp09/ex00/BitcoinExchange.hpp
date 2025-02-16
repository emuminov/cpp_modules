#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <string>
class BitcoinExchange
{
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& bc);
    BitcoinExchange& operator=(const BitcoinExchange& bc);
    ~BitcoinExchange();

    int print_exchange_rate_from_input(const std::string& file_name);

  private:
    enum e_error
    {
        ok,
        database_access_error,
        database_invalid,
        input_access_error,
    };
    typedef std::map<std::string, double>::iterator t_iterator;
    typedef std::pair<enum BitcoinExchange::e_error, std::string> t_error_object;

    static const std::string s_db_name;
    std::map<std::string, double> m_data;

    t_error_object _read_db();
    t_error_object _read_input(const std::string& file_name);

    t_error_object _handle_db_line(const std::string& curr_line);
    void _handle_input_line(const std::string& curr_line);
    void _print_exchange_rate_line(double value, double rate, const std::string& date_str) const;
    bool _is_date_valid(const std::string& date_str) const;
    bool _has_only_digits(const std::string& str) const;
    bool _is_a_double_str_representation(const std::string& nbr_str) const;
};
#endif
