/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:17:03 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/20 19:22:41 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Harl {
  public:
    Harl();
    ~Harl();
    void complain(std::string level);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};
