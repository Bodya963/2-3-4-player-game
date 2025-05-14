//бмблеотеки-------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <list>
#include <ctime>
#include <algorithm>
#include <termios.h>
#include <sys/time.h>
#include <sys/poll.h>
#include <sys/select.h>
#include <signal.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//----------------------------------

using namespace sf;

//-----define-----------------------

#define TAILSIZE 100
#define NAMESIZE 32
#define MAXHEIGHT 2000
#define MAXHWIDTH 4000