ALGORITHM CircuitProtectionSystem
1. Display welcome message and program title
2. INPUT: numberOfCircuits
3. IF numberOfCircuits ≤ 0 THEN
      DISPLAY "Invalid input"
      RETURN error
      END IF
4. OPEN "protection_report.txt" for writing
 5. IF file cannot be opened THEN
      DISPLAY error message
      RETURN error
      END IF
6. FOR each circuit from 1 to numberOfCircuits DO
      CALL ProcessCircuit()
       END FOR
    
7. CLOSE report file
8. DISPLAY success message
9. RETURN success
END MAIN

PROCEDURE ProcessCircuit():
1. CREATE new CircuitProtection object
2. DO-WHILE input is invalid
      CALL GetCircuitDetails()
      IF NOT ValidateInput() THEN
      DISPLAY error message
      CONTINUE loop
      ELSE
      BREAK loop
      END IF
      END DO-WHILE
3. CALL CalculateLoadCurrent()
           loadCurrent = totalPower / supplyVoltage
4. CALL CalculateDesignCurrent()
           designCurrent = loadCurrent * 1.25
5. CALL RecommendProtectionRating()
6. CALL DisplayProtectionReport()
7. CALL SaveReportToFile()
END PROCEDURE
PROCEDURE GetCircuitDetails():
    1. INPUT: circuitName
    2. INPUT: supplyVoltage (Volts)
    3. INPUT: totalPower (Watts)

END PROCEDURE


PROCEDURE ValidateInput():
    1. IF supplyVoltage > 0 AND totalPower > 0 THEN
           RETURN true
       ELSE
           RETURN false
       END IF

END PROCEDURE


PROCEDURE RecommendProtectionRating():
    1. standardRatings = { 6 A, 10 A, 16 A, 20 
  A, 25 A, 32 A, 40 A, and 63 A}
    2. recommendedRating = -1
    
    3. FOR each rating IN standardRatings DO
           IF rating ≥ designCurrent THEN
               recommendedRating = rating
               protectionStatus = "Device selected."
               BREAK loop
           END IF
       END FOR
    
    4. IF recommendedRating = -1 THEN
           protectionStatus = "No standard rating available for this design current."
       END IF

END PROCEDURE
