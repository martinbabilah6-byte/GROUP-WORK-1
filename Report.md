PRESENTATION FOR GROUP 2.1
NAMES OF MEMBERS	                 INDEX NUMBERS	                ROLE/CONTRIBUTIONS
ENYOWU JUSTICE KWAME	             01245565B	                    Project Lead
OFOSU DAVID OPOKU	                 01243218B	                    Algorithm Writer
AMUYAO FESTUS KWETEY	             01244186B	                    Pseudocode Writer
MISBAAHU FUSEINI	                 01240271B	                    Flowchat Designer
RICHMOND AFARI	                   01245919B	                    C++ Programmer
EZRA ARMOO ENISON	                 01243736B	                    C++ Programmer
BENSAH JUNIOR JOSEPH	             01242875B	                    Testing Lead
QUARSHIE DENNIS WISE	             01242874B	                    GitHub Manager
LEMBOE MARVELOUS MARSHAL	         01242579B	                    Documentation Lead
MARTIN BABILAH	                   01240920B	                    Presentation Lead

***What this program does***
This program is a simple Circuit Protection selection system.
It helps the user choose a standard protective device rating (such as a fuse or circuit breaker) for one or more electrical circuits based on:
-the circuit name,
-supply voltage,
-total load power.

For each circuit, it calculates:
-load current = total power ÷ supply voltage,
-design current = load current × 1.25,
then selects the smallest standard rating from a predefined list that is equal to or exceeds the design current.
It prints the result to the console and saves a full report to protection_report.txt.

***How to run the code***
1. Compile C++ program.cpp with a C++ compiler.
2. Run the compiled executable:
3. Enter:
-The number of circuits to assess,
-for each circuit: enter the circuit name, supply voltage, and total load power.
After input, the program displays a protection report for each circuit and writes the same report to protection_report.txt

***What problem it solves***
This code solves the problem of selecting an appropriate protective device rating based on circuit load characteristics. It ensures:
the circuit design uses positive voltage and power values,
-	the load current is calculated correctly,
-	the design current includes a safety margin (25% extra),
-	the chosen device rating is a standard available rating.
It is useful for basic electrical design support in a classroom or small engineering tool.

***Explanation of all functions***
	#Class CircuitProtection: This class stores circuit parameters and performs all calculations for one circuit.

#Void setCircuitDetails()
-	Asks the user to enter the circuit name, supply voltage, and total load power.
-	Uses:
-	cin >> ws;
-	getline(cin, circuitName);

*Why cin >> ws; is used:
cin >> ws consumes and discards any leading whitespace characters left in the input buffer.
This is important after previous input operations like cin >> numberOfCircuits; which can leave a newline character behind.
Without it, `getline` could read an empty string instead of the intended circuit name.

*Why getline(cin, circuitName); is used:
getline reads an entire line of user input, including spaces.
This allows the circuit name to contain spaces, e.g. Bedroom Lighting.

#Bool validateDetails()
Checks that supplyVoltage and totalPower are both positive.
If any of the input is not positive, prints an error and returns `false`.
Returns `true` only when input values are valid or positive.

#Void calculateLoadCurrent()
-	Calculate loadCurrent = totalPower / supplyVoltage
This is the electrical current drawn by the load under normal operating voltage.

#Void calculateDesignCurrent()
-	Calculate designCurrent = loadCurrent x 1.25;
This adds a 25% safety margin to account for startup currents or unexpected load increases.

#Void recommendProtectionRating()
-	Defines a vector of standard ratings {6, 10, 16, 20, 25, 32, 40, 63}
-	Finds the first rating that is greater than or equal to designCurrent.
-	Stores the chosen rating in recommendedRatin.
-	Sets protectionStatus to either:
i.	Device selected."` if a rating was found,
ii.	"No standard rating available for this design current."` if none of the standard ratings are large enough.

#Void displayProtectionReport()
-	Prints the protection report to the console:
-	Circuit name
-	Load current
-	Design current
-	Recommended device rating (if found)
-	Status


#Void saveReportToFile(ofstream & report)
-	Writes the same protection report into the given output file stream.
-	This ensures the report is saved persistently to `protection_report.txt`.

#Main() behavior
The main function orchestrates the program to:
1. Print a welcome banner and project title.
2. Ask the user for the number of circuits to assess.
3. Open the output file `protection_report.txt`.
4. For each circuit:
   - Create a `CircuitProtection` object.
   - Call `setCircuitDetails()` until valid input is entered.
   - Compute load and design currents.
   - Determine a recommended protection rating.
   - Display the report.
   - Save the report to the file.
5. Close the file.
6. Confirm the report is saved.

Future improvement ideas
1. Input validation for circuit name:
-	ensure non-empty names,
-	trim extra spaces.

2. Support more standard device ratings:
-	add additional values like 50, 63, 80, 100 A, etc.

3. Add options for different device types:
-	fuse vs circuit breaker,
-	trip curve type or derating factors.

4. Handle multiple voltage systems:
-	single-phase vs three-phase,
-	allow line-to-line or line-to-neutral voltage selection.

5. Improve user interface:
-	menu-driven options,
-	ability to load circuit data from a file,
-	ability to review previously saved reports.

6. Add unit conversion:
-	let users enter power in kW or voltage in different units.

7. Add error handling for file I/O:
-	handle write failures at runtime,
-	allow user to choose report filename.

8. Add comments and documentation inside the code:
-	this would make the program easier to maintain and extend.



Summary
-	C++ program.cpp calculates protective device ratings for user-entered circuits.
-	It uses cin >> ws; getline(...) to read circuit names safely.
-	It validates input, calculates currents, selects a standard rating, and writes a report.
-	Future improvements include richer rating data, file input, more validation, and expanded electrical support
