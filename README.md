# Duel
A program that simulates a duel between 3 shooters.
<br /><br />
The first shooter, Aaron, is a poor shot and only hits his target with a proability of 1/3.

The second shooter, Bob, is a bit better and hits his target with a proability of 1/2.

The third shooter, Charlie, is an expert marksman and never misses.
<br /><br />
To compensate for the inequities in their marksmanship skills, the three decided that they<br />
would fire in turns, starting with Aaron, followed by Bob, and then by Charlie. The cycle<br /> 
would repeat until there was one man standing.
<br /><br />
The duel is repeated 10,000 times with the wins of the shooters' wins being recorded.<br />
Afterwards, the winning probabilities of each shooter are printed out.


## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/duel.git
   ```
    or [download as ZIP](https://github.com/cramaechi/duel/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd duel
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./duel
```

Sample Output:
```
Aarons winning probability: 35.56%                                                                                    
                                                                                                                      
Bobs winning probability: 42.03%                                                                                      
                                                                                                                      
Charlies winning probability: 22.41%
```
