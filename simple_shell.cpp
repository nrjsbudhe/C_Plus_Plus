#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1000
#define MAX_ARGS 100

/**
 *  @brief Parse the command line into a vector of arguments. Check for mismatched quotes. Handle both quoted and unquoted tokens. Eliminate white spaces.
 *  @param line The command line to parse.
 *  @param args The vector of arguments to populate.
 *  @param has_mismatched_quotes flag to indicate if mismatched quotes were detected.
 *  @returns void.
 */

void parse_command(const std::string& line, std::vector<std::string>& args, bool& has_mismatched_quotes) 
{
    std::istringstream stream(line);
    std::string token;
    has_mismatched_quotes = false;

    while (stream >> std::ws) 
    {
        char next_char = stream.peek();

        // Check for quoted tokens
        if (next_char == '\'' || next_char == '"') 
        {   
            // Extract the quote character
            char quote_char = stream.get(); 

            // Return if mismatched quotes are detected
            if (!std::getline(stream, token, quote_char) || stream.eof()) {
                has_mismatched_quotes = true;
                return;
            }

            // Push the quoted token into the args vector
            if(!token.empty())
            {
            args.push_back(token);
            }

            // Move stream past the closing quote
            stream >> std::ws;
        } 
        
        // Check for unquoted tokens
        else 
        {
            stream >> token;
            if(!token.empty())
            {
                args.push_back(token);
            }
            // Move stream past the token
            stream >> std::ws;
        }
    }
}

/**
 * @name Execute Command
 * @brief Execute the command in a child process. Wait for the child process to complete. Print an error message if the command exits with a non-zero status.
 * @param args The vector of arguments to execute.
 * @returns void.
 */

void execute_command(const std::vector<std::string>& args) 
{    
    std::vector<char*> c_args;

    for (const auto& arg : args) 
    {
        c_args.push_back(const_cast<char*>(arg.c_str()));
    }
    c_args.push_back(nullptr);

    pid_t pid = fork();     // Create a child process

    if (pid < 0) 
    {
        std::cerr << "error: fork failed\n";
        return;
    } 
    else if (pid == 0) 
    {
        execvp(c_args[0], c_args.data());
        std::cerr << "error: command not found\n";
        exit(EXIT_FAILURE);
    } 
    else 
    {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) 
        {
            std::cerr << "error: command exited with code " << WEXITSTATUS(status) << "\n";
        }
    }
}

/**
 * @name Change Directory
 * @brief Change the current working directory to the specified path. Print an error message if the operation fails.
 * @param path The path to change the current working directory to.
 * @returns bool true if the operation is successful, false otherwise.
 */

bool change_directory(const std::string& path) 
{
    if (chdir(path.c_str()) != 0) 
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int main() 
{
    std::string line;

    while (true) 
    {
        // Print the prompt
        std::cerr << "$ ";                      

        // Read a line of input
        if (!std::getline(std::cin, line))      
        {
            break;  // EOF
        }

        // Check for line length
        if (line.length() > MAX_LINE_LENGTH)    
        {
            std::cerr << "error: command line too long\n";
            continue;
        }

        std::vector<std::string> args;
        bool has_mismatched_quotes = false;
        parse_command(line, args, has_mismatched_quotes);

        // Check for number of arguments
        if(args.size() > MAX_ARGS) 
        {
            std::cerr << "error: too many arguments\n";
            continue;
        }

        // Check for mismatched quotes
        if (has_mismatched_quotes) 
        {
            std::cerr << "error: mismatched quotes\n";
            continue;
        }

        // Check for empty command
        if (args.empty()) 
        {
            continue;
        }

        // Exexute the command - handle commands exit, cd and other commands
        if (args[0] == "exit") 
        {
            break;
        }
        else if (args[0] == "cd") 
        {   
            // Check for number of arguments
            if (args.size() != 2) 
            {
                std::cerr << "error: cd requires one argument\n";
            } 
            else 
            {
                if(!change_directory(args[1]))
                {
                    std::cerr << "error: cd failed\n";
                };
            }
        } 
        else 
        {
            execute_command(args);
        }
    }

    return 0;
}