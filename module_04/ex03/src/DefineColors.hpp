#ifndef DEFINECOLORS_HPP
# define DEFINECOLORS_HPP

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define UNDERLINE(text) "\033[4m" << text << "\033[0m"

# define BLUE(text) "\033[34m" << text << "\033[0m"
# define RED(text) "\033[31m" << text << "\033[0m"
# define GREEN(text) "\033[32m" << text << "\033[0m"
# define YELLOW(text) "\033[33m" << text << "\033[0m"
# define MAGENTA(text) "\033[35m" << text << "\033[0m"
# define CYAN(text) "\033[36m" << text << "\033[0m"
# define BROWN(text) "\033[33m" << text << "\033[0m"
# define WHITE(text) "\033[37m" << text << "\033[0m"
# define BLACK(text) "\033[30m" << text << "\033[0m"

# define BG_BLUE(text) "\033[44m" << text << "\033[0m"
# define BG_RED(text) "\033[41m" << text << "\033[0m"
# define BG_GREEN(text) "\033[42m" << text << "\033[0m"
# define BG_YELLOW(text) "\033[43m" << text << "\033[0m"
# define BG_MAGENTA(text) "\033[45m" << text << "\033[0m"
# define BG_CYAN(text) "\033[46m" << text << "\033[0m"
# define BG_BROWN(text) "\033[43m" << text << "\033[0m"
# define BG_WHITE(text) "\033[47m" << text << "\033[0m"
# define BG_BLACK(text) "\033[40m" << text << "\033[0m"

#endif
