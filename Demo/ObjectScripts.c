/**
 * Maniac Mansion: Demo
 *
 * Object Scripts
 */

/**
 * Room 1: Front of Mansion
 */

/** Stamps **/
roomobj-1-132.dmp

Pull.Pickup {
    [001A] pickupObject(0);
    [001C] printEgo("Hmm, they're uncanceled.");
    [0034] Var[81] = 1;
    [0037] stopObjectCode();
}

/** Mailbox **/
roomobj-1-17.dmp

Open {
    [001D] setState08();                                                        // Open mailbox
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] clearState08();                                                      // Close mailbox
    [0020] stopObjectCode();                                                    // --
}

Use {
    [0021] doSentence(11,255,263);                                              // Use _cmdObject2 with Mailbox
    [0025] stopObjectCode();                                                    // --
}


/** Mailbox Flag **/
roomobj-1-18.dmp

Open {
    [001E] doSentence(1,254,255);                                               // Open _cmdObject with _cmdObject2
    [0022] stopObjectCode();                                                    // --
}

Close {
    [0023] doSentence(2,254,255);                                               // Close _cmdObject with _cmdObject2
    [0027] stopObjectCode();                                                    // --
}

Pull {
    [0028] setState08();                                                        // Raise Flag
    [0029] stopObjectCode();                                                    // --
}

Push {
    [002A] clearState08();                                                      // Lower Flag
    [002B] stopObjectCode();                                                    // --
}

Use {
    [002C] if (getState08(activeObject)) {                                      // If Flag Up
    [002F]   clearState08();                                                    //  Lower Flag
    [0030] } else {                                                             // -
    [0033]   setState08();                                                      //  Raise Flag
    [0034] }
    [0034] stopObjectCode();                                                    // --
}



/** Bushes **/
roomobj-1-19.dmp

Open.Pull.PickUp {
    [001C] setState08();                                                        // Open, Pull, Pickup: Remove Bushes
    [001D] stopObjectCode();                                                    // --
}


/** Grating **/
roomobj-1-20.dmp

Open {
    [0027] if (getState04(activeObject)) {                                      // Has grate been fixed?
    [002A]   VAR_RESULT = getActorBitVar(VAR_EGO,kActorMiscFlagStrong);         //  No. Check if kid is strong
    [002E]   if (VAR_RESULT == 1) {                                             //  Strong?
    [0033]     printEgo("Easy!");                                               //   Yes
    [003A]     goto 0062;
    [003D]   } else {                                                           // -
    [0040]     printEgo("I can't budge it. It's rusted shut.");
    [005F]   }
    [005F] } else {                                                             // -
    [0062]   setState08();                                                      // Grate is open
    [0063]   setState08(213);                                                   // Grate is open
    [0065]   startSound(7);                                                     // Sound Door Open
    [0067] }
    [0067] stopObjectCode();                                                    // --
}

Close {
    [0068] clearState08();                                                      // Grate is closed
    [0069] clearState08(213);                                                   // Grate is closed
    [006B] stopObjectCode();                                                    // --
}

Push.Pull {
    [006C] if (!getState08(activeObject)) {                                     // Push
    [006F]   doSentence(1,20,0);                                                //  Open Grating
    [0073] } else {                                                             // -
    [0076]   doSentence(2,20,0);                                                //  Close Grating
    [007A] }
    [007A] stopObjectCode();                                                    // --
}

Fix.Unlock.Use {
    [007B] if (activeObject2 == 119) {                                          // Use Tools with Grate
    [007F]   clearState04();                                                    // Grate can be opened by anyone
    [0080]   doSentence(1,20,0);
    [0084] }
    [0084] stopObjectCode();                                                    // --
}

WalkTo {
    [0085] if (getState08(activeObject)) {                                      // Walk To
    [0088]   loadRoomWithEgo(213,29);                                           // Enter room Underhouse
    [008B] }
    [008B] stopObjectCode();                                                    // --
}


/** Door mat **/
roomobj-1-21.dmp

Pull.PickUp {
    [001E] if (getState08(activeObject)) {                                      // Pull/Pickup
    [0021]   printEgo("I'll leave it here.");
    [0033] } else {                                                             // -
    [0036]   setState08();                                                      //  Move Doormat
    [0037] }
    [0037] stopObjectCode();                                                    // --
}

Push {
    [0038] clearState08();                                                      // Move doormat back
    [0039] stopObjectCode();                                                    // --
}


/** Front Door Key **/
roomobj-1-22.dmp

PickUp {
    [0017] pickupObject(0);                                                     // Pickup Key
    [0019] stopObjectCode();                                                    // --
}

Use {
    [001A] if (activeObject2 == 28) {                                           // Use key with Front Door
    [001E]   clearState04(28);                                                  //  Unlock Front Door
    [0020]   doSentence(1,28,0);                                                //  Open Front Door
    [0024] } else {                                                             // -
    [0027]   printEgo("It doesn't work.");
    [0037] }
    [0037] stopObjectCode();                                                    // --
}


/** Undeveloped Film **/
roomobj-1-23.dmp


/** Package **/
roomobj-1-24.dmp

PickUp {
    [0021] pickupObject(0);                                                     // Pickup Package
    [0023] if (Var[81] == 0) {                                                  // if Stamps Taken == No
    [0028]   pickupObject(132);                                                 //  Pickup Stamps
    [002A]   setOwnerOf(132,14);                                                //  Set owner of stamps to Green Tentacle
    [002D] }
    [002D] stopObjectCode();                                                    // --
}

Give {
    [002E] if (VAR_ACTIVE_ACTOR < 8) {                                          // Give
    [0033]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  To Kid
    [0036] }
    [0036] stopObjectCode();                                                    // --
}

Read {
    [0037] printEgo("To: Weird Ed");                                            // Read
    [0043] stopObjectCode();                                                    // --
}

Open.Pull {
    [0044] if (Var[81] == 0) {                                                  // if Stamps Taken == No
    [0049]   if (getState08(activeObject)) {                                    //  if Package available
    [004C]     setOwnerOf(132,VAR_EGO);                                         //   Kid owns Stamps
    [004F]   } else {                                                           // -
    [0052]     pickupObject(132);                                               // Pickup Stamps
    [0054]   }
    [0054]   printEgo("Some uncanceled stamps came off!");
    [0072]   Var[81] = 1;                                                       // Stamps Taken = Yes
    [0075] } else {                                                             // -
    [0078]   printEgo("That would be illegal.");
    [008D] }
    [008D] stopObjectCode();
}


/** Exit to Room 44 **/
roomobj-1-240.dmp


/** Envelope **/
roomobj-1-25.dmp

/** Mailbox **/
roomobj-1-263.dmp

Open {
    [001D] setState08(17);                                                      // Open
    [001F] stopObjectCode();                                                    // --
}

Close {
    [0020] clearState08(17);                                                    // Close
    [0022] stopObjectCode();                                                    // --
}

Read {
    [0023] printEgo("Solicitors will be eaten.");
    [003B] stopObjectCode();
}

/** Bushes **/
roomobj-1-264.dmp


/** Contract **/
roomobj-1-27.dmp

/** Front Door **/
roomobj-1-28.dmp

Open {
    [0026] if (!getState04(activeObject)) {                                     // Is Door unlocked
    [0029]   startScript(4);                                                    //  start Door: Open
    [002B]   setState08(34);                                                    //  Open Front Door (from room 10)
    [002D] } else {                                                             // else
    [0030]   startScript(31);                                                   //  start Print "The door is locked"
    [0032] }
    [0032] stopObjectCode();                                                    // --
}

Close {
    [0033] startScript(5);                                                      // start Door: Close
    [0035] clearState08(34);                                                    // close Front Door (from room 10)
    [0037] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0038] if (activeObject2 == 22) {                                           // Use Front Door Key In Front Door
    [003C]   clearState04();                                                    //  Unlock Front door
    [003D]   doSentence(1,28,0);                                                //  Open Front Door
    [0041] } else {                                                             // -
    [0044]   startScript(33);                                                   //  start Print "I can't unlock the door with this."
    [0046] }
    [0046] stopObjectCode();
}

Lock {
    [0047] setState04();
    [0048] doSentence(2,28,0);                                                  //  Close Front Door
    [004C] stopObjectCode();                                                    // --
}

WalkTo {
    [004D] if (getState08(activeObject)) {
    [0050]   loadRoomWithEgo(34,10);                                            //  Kid enters Room 10 at Front Door
    [0053] }
    [0053] stopObjectCode();
}

/** Tombstone **/
roomobj-1-29.dmp

Read {
    [001B] printEgo("And good riddance!");
    [002D] stopObjectCode();
}


/** Tombstone **/
roomobj-1-30.dmp

Read {
    [001B] printEgo("Another one bites the dust!");
    [0034] stopObjectCode();
}


/** Tombstone **/
roomobj-1-31.dmp


/** Doorbell **/
roomobj-1-386.dmp

Push.Use {
    [001E] startScript(49);                                                     // start Handle Doorbell
    [0020] stopObjectCode();
}

Read {
    [0021] printEgo("This is the home of Dr. Fred,/Nurse Edna, Weird Ed, Dead Cousin Ted,/Green Tentacle and Purple Tentacle.");
    [007B] stopObjectCode();
}


/** Cassette Player **/
roomobj-3-207.dmp

TurnOn {
    [0025] if (!getState08(47)) {                                               // Cassette Tape == Not In Player
    [0029]   if (!getState08(124)) {                                            //  Circuit Breaker == Power On
    [002D]     setState08(207);                                                 //   Cassette Player has tape
    [002F]     startScript(48);                                                 //   start Tape Player: Play Tape
    [0031]   }
    [0031] } else {
    [0034]   printEgo("There's no tape in the player.");
    [004F] }
    [004F] stopObjectCode();
}

TurnOff {
    [0050] if (getState08(207)) {                                               // Cassette Player has tape?
    [0054]   clearState08(207);                                                 //  Remove Tape
    [0056]   stopScript(48);                                                    //   stop Tape Player: Play Tape
    [0058]   print(255," ");
    [005C] }
    [005C] stopObjectCode();
}

Use {
    [005D] if (activeObject2 == 156) {                                          // Use Cassette Tape with Cassette Player
    [0061]   setOwnerOf(156,14);                                                // Green Tentacle owns Tape
    [0064]   clearState08(47);                                                  // Tape Hidden
    [0066]   clearState02(47);                                                  // Tape Hidden
    [0068] }
    [0068] stopObjectCode();
}

/** Couch **/
roomobj-3-273.dmp

Push.Pull {
    [0019] printEgo("I can't budge it.");
    [0029] stopObjectCode();
}


/** Door **/
roomobj-3-38.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(37);                                                      // Open Door (in room 10)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(37);                                                    // Close Door (in room 10)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(37,10);                                            //  Enter Room 10 at Door
    [002A] }
    [002A] stopObjectCode();                                                    // --
}


/** Old Fashioned Radio **/
roomobj-3-39.dmp

Open {
    [002D] setState08();                                                        // Open Radio
    [002E] Var[29] = 0;                                                         // Radio Off
    [0031] stopSound(16);
    [0033] stopSound(23);
    [0035] stopObjectCode();                                                    // --
}

Close {
    [0036] clearState08();                                                      // Close Radio
    [0037] stopObjectCode();                                                    // --
}

Fix {
    [0038] if (activeObject2 == 40) {                                           // if Fix Radio with Radio Tube
    [003C]   clearState08(40);                                                  //  Show radio tube
    [003E]   clearState02(40);                                                  // Show radio tube
    [0040]   setOwnerOf(40,0);                                                  //  Radio tube has no owner
    [0043] } else if (getState08(40)) {
    [004A]   printEgo("That doesn't seem to work.");
    [0062] }
    [0062] stopObjectCode();                                                    // --
}

TurnOn {
    [0063] clearState08();                                                      // Close Radio
    [0064] if (!getState08(40)) {                                               //  if Radio Tube not taken
    [0068]   if (!getState08(124)) {                                            //   if Power is on
    [006C]     if (Var[29] == 0) {                                              //    if Radio Not on
    [0071]       Var[29] = 1;                                                   //     Radio On
    [0074]       startSound(16);                                                //     Play Music
    [0076]     }
    [0076]   }
    [0076] } else {                                                             // -
    [0079]   printEgo("I can't get it to work.");
    [008D] }
    [008D] stopObjectCode();                                                    // --
}

TurnOff {
    [008E] clearState08();
    [008F] if (Var[29] == 0) {                                                  // if Radio == Off?
    [0094]   printEgo("It wasn't on.");
    [00A1] } else {                                                             // -
    [00A4]   Var[29] = 0;                                                       //  Radio = Off
    [00A7]   stopSound(16);
    [00A9]   stopSound(23);
    [00AB] }
    [00AB] stopObjectCode();                                                    // --
}

Use {
    [00AC] clearState08();
    [00AD] if (Var[29] == 0) {                                                  // if Radio == off
    [00B2]   printEgo("It's not turned on.");
    [00C4] } else {                                                             // -
    [00C7]   startSound(23);								
    [00C9] }
    [00C9] stopObjectCode();                                                    // --
}

/** Radio Tube **/
roomobj-3-40.dmp

PickUp {
    [001E] if (VAR_EGO == 5) {                                                  // If kid == Bernard
    [0023]   pickupObject(0);                                                   //  Pickup
    [0025] } else {                                                             // -
    [0028]   printEgo("I don't know how this stuff works!");
    [0046] }
    [0046] stopObjectCode();                                                    // --
}

Use {
    [0047] doSentence(6,255,254);                                               // Fix _cmdObject with _cmdObject2
    [004B] stopObjectCode();                                                    // --
}


/** Glass Chandelier **/
roomobj-3-41.dmp


/** Broken Chandelier **/
roomobj-3-42.dmp


/** Old Rusty Key **/
roomobj-3-43.dmp

PickUp {
    [0021] pickupObject(0);                                                     // Pickup
    [0023] stopObjectCode();                                                    // --
}

Use {
    [0024] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0028] stopObjectCode();                                                    // --
}

/** Cabinet Door **/
roomobj-3-44.dmp

Open {
    [0020] startScript(4);                                                      // start Door: Open
    [0022] stopObjectCode();                                                    // --
}

Close {
    [0023] startScript(5);                                                      // start Door: Close
    [0025] stopObjectCode();                                                    // --
}


/** Key **/
roomobj-3-445.dmp

Pull.PickUp {
    [0017] printEgo("I can't reach it.");
    [0027] stopObjectCode();
}

/** Window **/
roomobj-3-45.dmp

/** Window **/
roomobj-3-46.dmp

/** Cassette Tape **/
roomobj-3-47.dmp

PickUp {
    [0023] if (getState08(207)) {                                               // Cassette Player is playing?
    [0027]   printEgo("It's still playing!");
    [003A] } else {                                                             // -
    [003D]   setOwnerOf(156,VAR_EGO);                                           // Kid owns Tape
    [0040]   setState08();                                                      // Tape Taken
    [0041]   setState02();                                                      // Tape Taken
    [0042] }
    [0042] stopObjectCode();
}
TurnOn {
    [0043] if (!getState08(activeObject)) {                                     // If Casette Player Off
    [0046]   doSentence(4,207,0);                                               //  Turn On Cassette Player
    [004A] }
    [004A] stopObjectCode();
}

TurnOff {
    [004B] if (!getState08(activeObject)) {                                     // If Casette Player On
    [004E]   doSentence(5,207,0);                                               //  Turn Off Cassette Player
    [0052] }
    [0052] stopObjectCode();                                                    // --
}


/** Door **/
roomobj-3-93.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(102);                                                     // Door Open (other side)
    [001E] stopObjectCode();
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(102);                                                   // Door Close (other side)
    [0023] stopObjectCode();
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // Door is open?
    [0027]   loadRoomWithEgo(102,5);                                            // Kid enters Library at Door
    [002A] }
    [002A] stopObjectCode();                                                    // --
}

/**
 * Room 5: Library
 */


/** Door **/
roomobj-5-102.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(93);                                                      // Open Door (Room 3)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(93);                                                    // Close Door (Room 3)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(93,3);                                             //  Enter Room Downstairs Lounge Room
    [002A] }
    [002A] stopObjectCode();                                                    // --
}


/** Phone **/
roomobj-5-103.dmp

Use {
    [0019] startScript(15);                                                     // start Phone: Disconnect
    [001B] startScript(12);                                                     // start Pin: Entry - Edna Phone Number
    [001D] stopObjectCode();
}

PickUp {
    [001E] startScript(16);                                                     // start Phone: Disconnect if Kid walks too far away
    [0020] startSound(17);                                                      // sound
    [0022] stopObjectCode();
}

/** Cassette Tape **/
roomobj-5-156.dmp

PickUp {
    [0021] pickupObject(0);                                                     // Pickup Tape
    [0023] stopObjectCode();
}

Use {
    [0024] doSentence(11,255,254);                                              // Use Tape with _cmdObject2
    [0028] stopObjectCode();
}

/** Loose Panel **/
roomobj-5-236.dmp

Open {
    [0023] setState08();                                                        // Open Panel
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] clearState08();                                                      // Close Panel
    [0026] stopObjectCode();                                                    // --
}

Push.Pull {
    [0027] if (getState08(activeObject)) {                                      // Is Panel Open
    [002A]   clearState08();                                                    //  Close Panel
    [002B] } else {                                                             // -
    [002E]   setState08();                                                      //  Open Panel
    [002F] }
    [002F] stopObjectCode();                                                    // --
}


/** Lamp **/
roomobj-5-315.dmp

TurnOn {
    [0018] startSound(11);                                                      // sound Light Switch
    [001A] setBitVar(VAR_ROOM,1,0);                                             // VAR_ROOM has light
    [001E] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0020] Var[117] = 1;                                                        // Room light on
    [0023] stopObjectCode();                                                    // --
}

TurnOff {
    [0024] startSound(11);                                                      // sound Light Switch
    [0026] Var[117] = 0;                                                        // Room light off
    [0029] if (Var[118] == 0) {                                                 // Both Room Lights Off?
    [002E]   setBitVar(VAR_ROOM,1,1);                                           //  VAR_ROOM loses light
    [0032]   startScript(19);                                                   //  start Room Lights: Check for flashlight / room light status
    [0034] }
    [0034] stopObjectCode();                                                    // --
}


/** Lamp **/
roomobj-5-316.dmp

TurnOn {
    [0018] startSound(11);                                                      // sound Light Switch
    [001A] setBitVar(VAR_ROOM,1,0);                                             // VAR_ROOM has light
    [001E] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0020] Var[118] = 1;                                                        // Library light on
    [0023] stopObjectCode();                                                    // --
}

TurnOff {
    [0024] startSound(11);                                                      // sound Light Switch
    [0026] Var[118] = 0;                                                        // Library light off
    [0029] if (Var[117] == 0) {                                                 // Both Room Lights Off?
    [002E]   setBitVar(VAR_ROOM,1,1);                                           //  VAR_ROOM loses light
    [0032]   startScript(19);                                                   //  start Room Lights: Check for flashlight / room light status
    [0034] }
    [0034] stopObjectCode();                                                    // --
}



/** Staircase **/
roomobj-5-318.dmp

WalkTo {
    [001F] printEgo("Staircase out of order.");                                 // Walk To
    [0035] stopObjectCode();                                                    // --
}

Fix.Use {
    [0036] printEgo("I can't fix the stairs with that.");                       // Fix/Use
    [0053] stopObjectCode();                                                    // --
}

/** Chuck the plant **/
roomobj-5-319.dmp


/** Chair **/
roomobj-5-320.dmp


/** Sign **/
roomobj-5-440.dmp

Read {
    [0018] printEgo("Staircase out of order.");                                 // Read
    [002E] stopObjectCode();                                                    // --
}

Fix {
    [002F] if (activeObject2 == 119) {                                          // Use tools with Sign
    [0033]   printEgo("I'm not a carpenter.");
    [0046] } else {                                                             // -
    [0049]   printEgo("That won't work.");
    [0059] }
    [0059] stopObjectCode();                                                    // --
}


/**
 * Room 6: Pool Area
 */


/** Door **/
roomobj-6-104.dmp

Open {
    [0020] if (!getState04(activeObject)) {                                     // If door is unlocked
    [0023]   startScript(4);                                                    //  start Door: Open
    [0025]   setState08(92);                                                    //  Open Door (Storage room)
    [0027] } else {                                                             // -
    [002A]   startScript(31);                                                   //  start Print "The door is locked"
    [002C] }
    [002C] stopObjectCode();                                                    // --
}

Close {
    [002D] startScript(5);                                                      // start Door: Close
    [002F] clearState08(92);                                                    // Close Door (Storage room)
    [0031] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0032] if (activeObject2 == 125) {                                          // if Use Silver Key with Door
    [0036]   clearState04();                                                    //  Unlock Door
    [0037]   clearState04(92);                                                  //  Unlock Door (Storage room)
    [0039]   doSentence(1,104,0);                                               //  Execute Verb: "Open Door"
    [003D] } else {                                                             // -
    [0040]   startScript(33);                                                   //  start Print "I can't unlock the door with this."
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Lock {
    [0043] setState04();                                                        // Lock Door
    [0044] setState04(92);                                                      // Lock Door (Storage Room)
    [0046] doSentence(2,104,0);                                                 // Execute Verb: "Close Door"
    [004A] stopObjectCode();                                                    // --
    [004B] if (getState08(activeObject)) {                                      // Is Door Open
    [004E]   loadRoomWithEgo(92,36);                                            //  Enter Storage / Leading out to pool
    [0051] }
    [0051] stopObjectCode();                                                    // --
}


/** Gate **/
roomobj-6-105.dmp

Lock {

}

Open.Push.WalkTo {
    [001F] printEgo("It's sealed shut for the demo version.");
    [0041] stopObjectCode();
}

Close {
    [0042] printEgo("It's already closed.");
    [0056] stopObjectCode();
}


/** Swimming Pool **/
roomobj-6-106.dmp

WalkTo {
    [0021] if (!getState08(activeObject)) {                                     // If Pool Full
    [0024]   printEgo("I don't want to get wet!");
    [0039] } else {                                                             // -
    [003C]   printEgo("I'd better use the ladder.");
    [0054]   doSentence(13,139,0);                                              // Use Ladder Script
    [0058] }
    [0058] stopObjectCode();
}

Use {
    [0059] if (!getState08(activeObject)) {                                     // If Pool Full
    [005C]   if (activeObject2 == 99) {                                         //  if Glass Jar
    [0060]     Var[22] = 2;                                                     //   Glass Jar Contents = Radioactive Water
    [0063]     startScript(38);                                                 //   start Glass Jar: Name
    [0065]   }
    [0065] }
    [0065] stopObjectCode();
}


/** Radio **/
roomobj-6-107.dmp
WhatIs {
    [0017] printEgo("I can't reach it.");
    [0027] stopObjectCode();
}


/** Ladder **/
roomobj-6-139.dmp

WalkTo {
    [0018] loadRoomWithEgo(138,2);                                              // Enter Room 2, Bottom of Pool
    [001B] stopObjectCode();                                                    // --
}


/** Ladder **/
roomobj-6-272.dmp

WalkTo {
    [0018] printEgo("I'm not going down there%/%it's full of water!");          // Walk To
    [0041] stopObjectCode();                                                    // --
}

/** Pool Chair **/
roomobj-6-323.dmp

WhatIs {
    [001C] printEgo("I can't reach it.");                                       // What Is
    [002C] stopObjectCode();                                                    // --
}


/** Old Tree **/
roomobj-6-324.dmp


/**
 * Room 7: Kitchen
 */


/** Old Batteries **/
roomobj-7-100.dmp

Pickup {
    [0021] pickupObject(0);                                                     // Pikcup
    [0023] doSentence(13,56,0);                                                 // Walk To Refridgerator
    [0027] stopObjectCode();                                                    // --
}

Use {
    [0028] if (activeObject2 == 51) {                                           // Flashlight
    [002C]   Var[31] = 1;                                                       // Flashlight has Battery = Yes
    [002F]   Var[126] = 60;                                                     // Flashlight Battery Charge
    [0032]   setOwnerOf(100,0);                                                 // Remove Old Batteries
    [0035] }
    [0035] stopObjectCode();                                                    // --
}


/** Sealed Envelope **/
roomobj-7-234.dmp

Open {
    [0026] doSentence(1,201,0);                                                 // Open Sealed Envelope
    [002A] doSentence(14,234,0);                                                // Pickup Sealed Envelope
    [002E] stopObjectCode();                                                    // --
}

PickUp {
    [002F] clearState08();
    [0030] setState02();
    [0031] setOwnerOf(201,VAR_EGO);                                             // Kid owns Sealed Envelope
    [0034] Var[66] -= 2;                                                        // Item in Microwave -= 2
    [0037] stopObjectCode();                                                    // --
}

Use {
    [0038] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [003C] startScript(39);                                                     // Jar / Envelop: Name
    [003E] stopObjectCode();                                                    // --
}


/** Window **/
roomobj-7-276.dmp


/** Very dull knives **/
roomobj-7-277.dmp

PickUp {
    [0022] printEgo("They're glued to the wall.");                              // Pickup
    [003A] stopObjectCode();                                                    // --
}


/** Stove **/
roomobj-7-279.dmp

Use {
    [001F] printEgo("I don't think that's a good idea.");                       // Use
    [003C] stopObjectCode();                                                    // --
}

Open.Close.TurnOn.TurnOff {
    [003D] printEgo("I'd rather use the microwave.");                           // Open/Close/Turn On/Turn Off
    [0058] stopObjectCode();                                                    // --
}


/** Blood **/
roomobj-7-280.dmp

WhatIs {
    [0017] printEgo("Yuck!");                                                   // What Is
    [001E] stopObjectCode();                                                    // --
}


/** Door **/
roomobj-7-48.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(35);                                                      // Open Door (Main Entry)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(35);                                                    // Close Door (Main Entry)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(35,10);                                            //  Enter Main Entry
    [002A] }
    [002A] stopObjectCode();                                                    // --
}


/** Door **/
roomobj-7-49.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(62);                                                      // Open Door (Dining)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(62);                                                    // Close Door (Dining)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door Open
    [0027]   loadRoomWithEgo(62,37);                                            // Enter Dining
    [002A] }
    [002A] stopObjectCode();                                                    // --
}


/** Jar of Water **/
roomobj-7-50.dmp

PickUp {
    [002A] VAR_RESULT = isScriptRunning(23);                                    // is Timer: 1 Minute running
    [002D] if (VAR_RESULT == 1) {
    [0032]   printEgo("Ouch! It's still too hot!");
    [0049] } else {                                                             // -
    [004C]   clearState08();                                                    // Invisible Glass Jar
    [004D]   setState02();                                                      // Lock Glass Jar
    [004E]   setOwnerOf(99,VAR_EGO);                                            // Pickup Glass Jar
    [0051]   Var[66] -= 4;                                                      // Item in Microwave -= 4
    [0054] }
    [0054] stopObjectCode();                                                    // --
}


/** Flashlight **/
roomobj-7-51.dmp

TurnOn.PickUp {
    [0028] pickupObject(0);                                                     // Pickup Flashlight
    [002A] stopObjectCode();                                                    // --
    [002B] if (Var[31] >= 1) {                                                  // if Flashlight has Battery
    [0030]   Var[12] = 1;                                                       //  Flashlight Status = On
    [0033]   startScript(40);                                                   //  start Flashnight: Name
    [0035]   if (Var[31] == 1) {                                                //  if Flashlight has Battery == Old Battery
    [003A]     startScript(47);                                                 //   start Flashlight: Check
    [003C]   }
    [003C] } else {                                                             // -
    [003F]   printEgo("It needs batteries.");
    [0052] }
    [0052] stopObjectCode();                                                    // --
}

TurnOff {
    [0053] if (Var[31] >= 1) {                                                  // if Flashlight has Battery
    [0058]   Var[12] = 0;                                                       //  Flashlight Status = Off
    [005B]   startScript(40);                                                   //  start Flashnight: Name
    [005D]   stopScript(47);                                                    //  stop Flashlight: Check
    [005F] }
    [005F] stopObjectCode();                                                    // --
}

Use {
    [0060] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0064] stopObjectCode();                                                    // --
}

Give {
    [0065] if (VAR_ACTIVE_ACTOR < 8) {                                          // Player Kid?
    [006A]   doSentence(5,51,0);                                                //  Turn Off Flashlight
    [006E]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Give to kid
    [0071] }
    [0071] stopObjectCode();                                                    // --
}
}


/** Microwave Oven **/
roomobj-7-52.dmp

Open {
    [0028] if (!getState08(activeObject)) {                                     // If Microwave on
    [002B]   stopScript(21);                                                    //  stop Microwave
    [002D]   startScript(4);                                                    //  start Door: Open
    [002F]   if (getState08(50)) {                                              // if Jar of Water Microwaved
    [0033]     clearState02(50);
    [0035]     if (Var[22] == 2) {                                              // Glass Jar Contents == Radioactive Water
    [003A]       VAR_RESULT = isScriptRunning(23);
    [003D]       if (VAR_RESULT == 1) {                                         // if Timer: 1 Minute has not finished
    [0042]         Var[76] = 1;                                                 //  Death Method = Radioactive Steam
    [0045]         startScript(24);                                             //  Cutscene: Kid Dies
    [0047]       }
    [0047]     }
    [0047]   }
    [0047]   if (getState08(234)) {                                             // if Sealed Envelope Microwaved
    [004B]     clearState02(234);                                               //  Stamps Removed
    [004D]   }
    [004D] }
    [004D] stopObjectCode();
}

Close {
    [004E] startScript(5);                                                      // start Door: Close
    [0050] setState02(54);                                                      // Exploded Hamster Microwaved
    [0052] setState02(53);                                                      // Hamster microwaved
    [0054] setState02(50);
    [0056] setState02(234);
    [0058] stopObjectCode();                                                    // --
}

Use {
    [0059] startScript(22);                                                     // start Microwave: Put item in
    [005B] stopObjectCode();                                                    // --
}

TurnOn {
    [005C] startScript(36);                                                     // start Microwave:
    [005E] stopObjectCode();                                                    // --
}

TurnOff {
    [005F] stopScript(21);                                                      // stop Microwave
    [0061] stopObjectCode();                                                    // if Exploded Hamster Microwaved
}


/** Hamster **/
roomobj-7-53.dmp
PickUp {
    [0019] clearState08();                                                      // Lock Hamster
    [001A] setState02();                                                        //
    [001B] setOwnerOf(1,VAR_EGO);                                               // Kid owns hamster
    [001E] Var[66] = 0;                                                         // Item in Microwave = Empty
    [0021] stopObjectCode();                                                    // --
}

/** Exploded Hamster **/
roomobj-7-54.dmp


/** Faucet **/
roomobj-7-55.dmp

TurnOn {
    [001C] clearState08();                                                      // Faucet is on
    [001D] startSound(14);                                                      //
    [001F] stopObjectCode();                                                    // --
}

TurnOff {
    [0020] setState08();                                                        // Faucet is off
    [0021] stopSound(14);
    [0023] stopObjectCode();                                                    // --
}

Use {
    [0024] if (!getState08(activeObject)) {                                     // if Faucet is on
    [0027]   startScript(37);                                                   //  start Facet: Fill Gar/Sponge with Water
    [0029]   startScript(39);                                                   //  start Jar / Envelop: Name
    [002B] }
    [002B] stopObjectCode();                                                    // --
}


/** Refridgerator **/
roomobj-7-56.dmp

Open.Pull {
    [0024] startScript(4);                                                      // start Door: Open
    [0026] stopObjectCode();
}

Close.Push {
    [0027] startScript(5);                                                      // start Door: Close
    [0029] stopObjectCode();
}


/** Cheese **/
roomobj-7-57.dmp

PickUp {
    [0018] pickupObject(0);                                                     // Pickup Cheese
    [001A] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [001E] stopObjectCode();
}


/** Lettuce **/
roomobj-7-58.dmp

PickUp {
    [0019] pickupObject(0);
    [001B] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [001F] stopObjectCode();
}


/** Broken Bottles **/
roomobj-7-59.dmp

PickUp {
    [002B] pickupObject(0);
    [002D] doSentence(13,56,0);                                                 // Walk to Refridgerator
    [0031] stopObjectCode();
}

/** Can of Pepsi **/
roomobj-7-60.dmp

PickUp {
    [0024] pickupObject(0);
    [0026] doSentence(13,56,0);                                                 // Pick object
    [002A] stopObjectCode();                                                    // Walk to Refridgerator
}

Read {
    [002B] printEgo("12 fluid ounces (354 ml)");                                // --
    [0041] stopObjectCode();                                                    // Read
}

Use {
    [0042] doSentence(11,255,254);                                              // --
    [0046] stopObjectCode();                                                    // Use _cmdObject2 with _cmdObject
}

Give {
    [0047] if (VAR_ACTIVE_ACTOR > 8) {                                          // -
    [004C]   print(VAR_ACTIVE_ACTOR,"No thanks, it makes me burp.");            //  Only kids take drink
    [0066] } else {                                                             // -
    [0069]   startScript(43);                                                   //  start Give: Accept Item Check 2
    [006B] }
    [006B] stopObjectCode();
}


/** Chainsaw **/
roomobj-7-61.dmp

Pickup {
    [001E] pickupObject(0);
    [0020] stopObjectCode();
}

TurnOn.Use {
    [0021] printEgo("I think it's out of gas.");
    [0036] stopObjectCode();
}


/**
 * Room 8: Basement
 */

 /** Stairs **/
roomobj-8-121.dmp

WalkTo {
    [0018] loadRoomWithEgo(36,10);                                              // Enter Main Entry
    [001B] stopObjectCode();                                                    // --
}


/** Door **/
roomobj-8-122.dmp

Open {
    [001C] if (!getState08(activeObject)) {                                     // Is door locked
    [001F]   startScript(31);                                                   // start Print "The door is locked"
    [0021] }
    [0021] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0022] if (activeObject2 == 43) {                                           // Use Old Rusty Key with Door
    [0026]   startScript(4);                                                    //  start Door: Open
    [0028]   setState08(126);                                                   //  Open Door (Main Entry)
    [002A] } else {                                                             // -
    [002D]   startScript(33);                                                   //  start Print "I can't unlock the door with this."
    [002F] }
    [002F] stopObjectCode();                                                    // --
}

WalkTo {
    [0030] if (getState08(activeObject)) {                                      // if door is open
    [0033]   doSentence(2,122,0);                                               //   Close Door
    [0037]   loadRoomWithEgo(126,4);                                            //   Enter Basement
    [003A] }
    [003A] stopObjectCode();                                                    // --
}


/** Fuse Box **/
roomobj-8-123.dmp

Open {
    [001C] printEgo("Demo version does not meet UL standards./Temporarily sealed.");
    [0053] stopObjectCode();
}

Close {
    [0054] clearState08();                                                      // Close Fuse Box
    [0055] stopObjectCode();
}


/** Circuit Breaker **/
roomobj-8-124.dmp



/** Silvey Key **/
roomobj-8-125.dmp

PickUp {
    [001E] pickupObject(0);                                                     // Pick object
    [0020] stopObjectCode();                                                    // --
}

Use {
    [0021] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [0025] stopObjectCode();                                                    // --
}


/** Light Switch **/
roomobj-8-325.dmp

TurnOn {
    [0020] startSound(11);                                                      // sound Light Switch
    [0022] setBitVar(VAR_ROOM,1,0);                                             // VAR_ROOM Light On
    [0026] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0028] stopObjectCode();                                                    // --
}

TurnOff {
    [0029] startSound(11);                                                      // sound Light Switch
    [002B] setBitVar(VAR_ROOM,1,1);                                             // VAR_ROOM Light Off
    [002F] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0031] stopObjectCode();                                                    // --
}



/** Radioactive **/
roomobj-8-337.dmp

WhatIs {
    [0023] printEgo("Yuck! I'm not touching that!");
    [003D] stopObjectCode();
}


/** Furnace **/
roomobj-8-338.dmp

WalkTo {
    [001B] stopObjectCode();
}

WhatIs {
    [001C] printEgo("It's too hot!");
    [0029] stopObjectCode();
}

}


/** Nuclear Reactor **/
roomobj-8-339.dmp

WalkTo {
[0027] stopObjectCode();
}

TurnOff {
    [0028] printEgo("I don't want to start a melt down!");
    [0045] stopObjectCode();
}

Read {
    [0046] printEgo("Made in Chernobyl");
    [0057] stopObjectCode();
}

WhatIs {
    [0058] printEgo("It's too hot!");
    [0065] stopObjectCode();
}

}


/**
 * Room 10: Main Entry
 */


/** Stairs **/
roomobj-10-209.dmp

WalkTo {
    [0018] printEgo("I can't go up until you buy the game.");
    [0037] stopObjectCode();
}

/** Grandfather Clock **/
roomobj-10-269.dmp

Read {
[0023] printEgo("It's the correct time.");
[0038] stopObjectCode();
}


/** Vase **/
roomobj-10-270.dmp


/** Vase **/
roomobj-10-271.dmp


/** Front Door **/
roomobj-10-321.dmp

Open {
    [0020] doSentence(1,34,0);                                                  // Open Door
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] doSentence(2,34,0);                                                  // Close Door
    [0029] stopObjectCode();                                                    // --
}

WalkTo {
    [002A] doSentence(13,34,0);                                                 // Walk to Door
    [002E] stopObjectCode();                                                    // --
}


/** Door **/
roomobj-10-34.dmp

Open {
    [0020] startScript(4);                                                      // start Door: Open
    [0022] setState08(28);                                                      // Open Door (Outside Mansion)
    [0024] stopObjectCode();                                                    // --
}

Close {
    [0025] startScript(5);                                                      // start Door: Close
    [0027] clearState08(28);                                                    // Close Door (Outside Mansion)
    [0029] stopObjectCode();                                                    // --
}

WalkTo {
    [002A] if (getState08(activeObject)) {
    [002D]   loadRoomWithEgo(28,1);                                             // Enter Outside Mansion
    [0030] }
    [0030] stopObjectCode();                                                    // --
}


/** Gargoyle **/
roomobj-10-342.dmp

Push.Pull {
    [001C] startScript(46);                                                     // start Gargoyle: Open Basement Door
    [001E] stopObjectCode();                                                    // --
}

}


/** Gargoyle **/
roomobj-10-344.dmp
}


/** Door: Kitchen **/
roomobj-10-35.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(48);                                                      // Open Door (Kitchen)
    [001E] stopObjectCode();                                                    // --
}
Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(48);                                                    // Close Door (Kitchen)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door is open
    [0027]   loadRoomWithEgo(48,7);                                             //  Enter Kitchen at Door
    [002A] }
    [002A] stopObjectCode();
    }


/** Door: Basement **/
roomobj-10-36.dmp

Open.Close {
    [001A] printEgo("There's no handle here!");                                 // Open/Close
    [0030] stopObjectCode();
}

WalkTo {
    [0031] if (getState08(activeObject)) {                                      // If Door is open
    [0034]   loadRoomWithEgo(121,8);                                            //  Enter basement
    [0037] }                                                                    //  start  -= Does Nothing =-
    [0037] stopObjectCode();
}

/** Door **/
roomobj-10-37.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(38);                                                      // Open Door (Downstairs Lounge Room)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(38);                                                    // Close Door (Downstairs Lounge Room)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // If Door is open
    [0027]   loadRoomWithEgo(38,3);                                             //  Enter Downstairs Lounge Room
    [002A] }
    [002A] stopObjectCode();                                                    // --
}


/**
 * Room 31: Lab: Entry
 */


/** Door **/
roomobj-31-133.dmp

/** Door **/
roomobj-31-135.dmp

/** Control Panel **/
roomobj-31-347.dmp

/** Periscope **/
roomobj-31-348.dmp

/** Map of House **/
roomobj-31-416.dmp

/**
 * Room 33: Mansion At Distance (Lights Off)
 */

 /** <No Name> **/
roomobj-33-10.dmp

/** <No Name> **/
roomobj-33-11.dmp

/** <No Name> **/
roomobj-33-7.dmp

/** <No Name> **/
roomobj-33-73.dmp

/** <No Name> **/
roomobj-33-8.dmp

/** <No Name> **/
roomobj-33-9.dmp


/**
 * Room 36: Storage / Leading out to pool
 */

/** Shelves **/
roomobj-36-314.dmp


/** Door **/
roomobj-36-91.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(65);                                                      // Open Door (Dining)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(65);                                                    // Close Door (Dining)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if Door open
    [0027]   loadRoomWithEgo(65,37);                                            //  Enter Dining
    [002A] }
    [002A] stopObjectCode();
}

/** Door **/
roomobj-36-92.dmp

Open {
    [0020] if (!getState04(activeObject)) {                                     // if door unlocked
    [0023]   startScript(4);                                                    //  start Door: Open
    [0025]   setState08(104);                                                   //  Open Door (Pool Area)
    [0027] } else {                                                             // -
    [002A]   startScript(31);                                                   //  start Print "The door is locked"
    [002C] }
    [002C] stopObjectCode();                                                    // --
}

Close {
    [002D] startScript(5);                                                      // start Door: Close
    [002F] clearState08(104);                                                   // Close Door (Pool Area)
    [0031] stopObjectCode();                                                    // --
}

Unlock.Use {
    [0032] if (activeObject2 == 125) {                                          // if use with Silver Key
    [0036]   clearState04();                                                    //  Unlock Door
    [0037]   clearState04(104);                                                 //  Unlock Door (Pool Area)
    [0039]   doSentence(1,92,0);                                                //  Open Door
    [003D] } else {                                                             // -
    [0040]   startScript(33);                                                   //  start Print "I can't unlock the door with this."
    [0042] }
    [0042] stopObjectCode();                                                    // --
}

Lock {
    [0043] setState04();                                                        // Lock Door
    [0044] setState04(104);                                                     // Lock Door (Pool Area)
    [0046] doSentence(2,92,0);                                                  // Close Door
    [004A] stopObjectCode();                                                    // --
}

WalkTo {
    [004B] if (getState08(activeObject)) {                                      // If Door Open
    [004E]   loadRoomWithEgo(104,6);                                            //  Enter Pool Area
    [0051] }
    [0051] stopObjectCode();                                                    // --
}


/** Bottle of Developer **/
roomobj-36-94.dmp

PickUp {
    [0025] clearState08(98);                                                    // Grate
    [0027] clearState08(32);                                                    // Show Puddle of Developer (underhouse)
    [0029] clearState02(32);                                                    // Unlock Puddle of Developer (underhouse)
    [002B] setState08();                                                        // Lock Bottle
    [002C] setState02();                                                        // Hide Bottle
    [002D] startSound(9);                                                       // sound Piggy Bank Break
    [002F] printEgo("Whoops!");
    [0038] stopObjectCode();                                                    // --
}


/** Tentacle Chow **/
roomobj-36-95.dmp

PickUp {
    [001F] pickupObject(0);
    [0021] stopObjectCode();
}


/** Canned Goods **/
roomobj-36-96.dmp

PickUp {
    [001E] pickupObject(0);
    [0020] stopObjectCode();
}


/** Fruit Drinks **/
roomobj-36-97.dmp

Pickup {
    [0020] pickupObject(0);
    [0022] stopObjectCode();
}

Give {
    [0023] startScript(43);                                                     // SCRIPT 43 is missing
    [0025] stopObjectCode();                                                    // this script will crash the interpreter
}


/** Grate **/
roomobj-36-98.dmp

Open.Pull.Pickup {
    [001B] if (!getState08(activeObject)) {                                     // if develeper smashed
    [001E]   printEgo("Yech, broken glass!");
    [0031] } else {                                                             // -
    [0034]   printEgo("It's welded into the floor.");
    [004D] }
    [004D] stopObjectCode();                                                    // --
}


/** Glass Jar **/
roomobj-36-99.dmp

PickUp {
    [0026] pickupObject(0);                                                     // Pick object
    [0028] stopObjectCode();                                                    // --
}

Use {
    [0029] doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    [002D] stopObjectCode();                                                    // --
}

Give {
    [002E] if (VAR_ACTIVE_ACTOR < 8) {                                          // if actor is player kid
    [0033]   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Give to kid
    [0036] } else if (Var[22] > 0) {                                            // Glass Jar Contents != Empty
    [003E]   Var[134] = 1;                                                      //  Glass Jar has content = 1
    [0041]   startScript(43);                                                   //  Give: Accept Item Check 2
    [0043] }
    [0043] stopObjectCode();                                                    // --
}


/**
 * Room 37: Dining
 */


/** Chair **/
roomobj-37-281.dmp

/** Chair **/
roomobj-37-282.dmp


/** Candle **/
roomobj-37-283.dmp

Pickup {
    [0018] startScript(32);                                                     // start Print "Its too Heavy"
    [001A] stopObjectCode();                                                    // --
}


/** Candle **/
roomobj-37-284.dmp

Pickup {
    [0018] startScript(32);                                                     // start Print "Its too Heavy"
    [001A] stopObjectCode();
}



/** Candle **/
roomobj-37-285.dmp

Pickup {
    [0018] startScript(32);                                                     // start Print "Its too Heavy"
    [001A] stopObjectCode();
}


/** Light **/
roomobj-37-286.dmp

TurnOn.TurnOff.Use {
    [001B] printEgo("I can't reach it.");
    [002B] stopObjectCode();
}


/** Gravy Stain **/
roomobj-37-441.dmp

PickUp {
    [001D] printEgo("I don't do table cloths.");
    [0033] stopObjectCode();
}


/** Door **/
roomobj-37-62.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(49);                                                      // Door Open (Kitchen)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(49);                                                    // Door Close (Kitchen)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(49,7);                                             //  enter kitchen
    [002A] }
    [002A] stopObjectCode();                                                    // --
}



/** Old Rotting Turkey **/
roomobj-37-63.dmp

PickUp {
    [0024] pickupObject(63);
    [0026] stopObjectCode();
}



/** Week old Roast **/
roomobj-37-64.dmp

PickUp {
    [0020] pickupObject(64);
    [0022] stopObjectCode();
}


/** Door **/
roomobj-37-65.dmp

Open {
    [001A] startScript(4);                                                      // start Door: Open
    [001C] setState08(91);                                                      // Open Door (storage)
    [001E] stopObjectCode();                                                    // --
}

Close {
    [001F] startScript(5);                                                      // start Door: Close
    [0021] clearState08(91);                                                    // Close Door (storage)
    [0023] stopObjectCode();                                                    // --
}

WalkTo {
    [0024] if (getState08(activeObject)) {                                      // if door open
    [0027]   loadRoomWithEgo(91,36);                                            //  enter storage
    [002A] }
    [002A] stopObjectCode();                                                    // --
}


/**
 * Room 43: Keypad
 */

/** * **/
roomobj-43-287.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 10;
    [0017] print(255,"*");
    [001B] stopObjectCode();
}


/** 0 **/
roomobj-43-288.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 0;
    [0017] print(255,"0");
    [001B] stopObjectCode();
}

/** # **/
roomobj-43-289.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 11;
    [0017] print(255,"#");
    [001B] stopObjectCode();
}


/** 1 **/
roomobj-43-422.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 1;
    [0017] print(255,"1");
    [001B] stopObjectCode();
}


/** 2 **/
roomobj-43-423.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 2;
    [0017] print(255,"2");
    [001B] stopObjectCode();
}


/** 3 **/
roomobj-43-424.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 3;
    [0017] print(255,"3");
    [001B] stopObjectCode();
}


/** 4 **/
roomobj-43-425.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 4;
    [0017] print(255,"4");
    [001B] stopObjectCode();
}


/** 5 **/
roomobj-43-426.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 5;
    [0017] print(255,"5");
    [001B] stopObjectCode();
}


/** 6 **/
roomobj-43-427.dmp

WhatIs {
    [0013] startSound(15);
    [0015] Var[49] = 6;
    [0018] print(255,"6");
    [001C] stopObjectCode();
}


/** 7 **/
roomobj-43-428.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 7;
    [0017] print(255,"7");
    [001B] stopObjectCode();
}


/** 8 **/
roomobj-43-429.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 8;
    [0017] print(255,"8");
    [001B] stopObjectCode();
}


/** 9 **/
roomobj-43-430.dmp

WhatIs {
    [0012] startSound(15);
    [0014] Var[49] = 9;
    [0017] print(255,"9");
    [001B] stopObjectCode();
}


/**
 * Room 45: Mode Selection
 */

/** Hands on Demo **/
roomobj-45-243.dmp

WhatIs {
    [0012] setState08();
    [0013] stopMusic();
    [0014] Var[92] = 0;                                                         // Play Music Count = Start Intro
    [0017] Var[91] = 1;                                                         // Demo MOde = Hands on Demo
    [001A] stopObjectCode();
}


/** Self-Running Demo **/
roomobj-45-245.dmp

WhatIs {
    [0012] setState08();
    [0013] stopMusic();
    [0014] Var[92] = 0;                                                         // Play Music Count = Start Intro
    [0017] Var[91] = 2;                                                         // Demo Mode = Self Running
    [001A] stopObjectCode();
}

