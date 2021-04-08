# Requirements
## Introduction
 * Time and health are two precious comodities hence Hospital Management System is developed to manage patients effectively and improve both effectively. Managing patients at large hospitals and clinics may be a daunting task so to ease the process this system will enable one to perform CRUD operations on patients records and will facilitate a smooth process of the hospital functioning.
 * This topic was chosen because it gives me an opportunity to implement efficient data structures and provides me flexibilty to understand multiple C programming concepts.

## Research
### Patient Management Software System Features and Benefits
A health care providers main aim is, caring for patients and the buildup of everyday tasks like paperwork, scheduling and billing can get in the way of that. What is patient management software anyway? A patient management system is also known as clinic management software, patient manager software, medical patient software or medical practice management software (MPM). It refers to a number of efficient automated systems designed for tracking patient information, diagnoses, prescriptions, interactions and encounters within healthcare organizations like medical clinics or hospitals.

Some of these software applications focus on general patient management while others address specific processes such as inpatient tracking or blood testing. What they all have in common is that they make your job as a care provider smoother and more manageable.

### Benefits
Patient management information systems offer a range of benefits to providers big and small. Here are just a few of them:

### Ease burden on staff
Administrative staffing is one of the big drivers of high healthcare costs. Automating routine processes like patient flow management helps medical clinics and hospitals minimize their administrative expenses.

### Practice Management
A patient management app helps streamline every element of a medical office including recordkeeping, charting, patient scheduling, claims processing and billing functions.

### Timely Patient Care
Larger clinics and hospitals can enjoy similar benefits to smaller ones but have the added bonus of making patient-related processes more efficient. Because large practices have a heavy patient flow, the scheduling features of MPM is crucial to operations. Having an organized patient intake flow can mean the difference between a calm, orderly waiting room and a packed hotbed of irritation and frustration.

### Organization
Practice management software offers charting modules to keep patient data, charts, appointments and billing information together in a single digital file. Digital storage capability saves space for a neater, more welcoming office — not to mention less harried employees. 

## Cost and Features
Feature | Cost | Time
Create Patient Record | 
## Defining Our System
### Certain assumptions:
* Few systems already exists with which our system will interact
    * Hospital Management Application
    * Analytics System
    * Emergency Services
![Description](https://github.com/arc-arnob/LnT_Mini_Project/blob/main/1_Requirements/system.png)
### Explanation:
* Patient Management Application have few inbuilt features like:
    * Create a patient record
    * Delete a patient record
    * Read a patient record
    * Update a patient record
    * Save record to file
    * Read record from file 

* Since we have assumed that few systems already exists we can say that in future sprints new features could be added in which for instance patient record from PMS can be sent to HMS or Analytics or even to emegency services if some patient record shows abnormal pattern.

## SWOT ANALYSIS
![SWOT Analysis](https://github.com/arc-arnob/LnT_Mini_Project/blob/main/1_Requirements/swot.png)

# 4W&#39;s and 1&#39;H

## Who:

**TBD**

## What:

**TBD**

## When:

**TBD**

## Where:

**TBD**

## How:

**TBD**

# Detail requirements
## High Level Requirements: 
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | User shall be able to add new patient record | Techincal | TBD-S1 | 
| HR02 | User shall be able to read a patient record | Techincal | TBD-S1 |
| HR03 | User shall be able to update a patient record | Techincal | TBD-S1 |
| HR04 | User shall be able to delete a patient record | Techincal | TBD-S1 |
| HR05 | User shall be able to save records in a file | Techincal | TBD-S1 |
| HR06 | User shall be able to read data from a file | Techincal | TBD-S1 |
| HR07 | Data should not be lost in case of faliure | Scenario | FUTURE |
| HR08 | Data should always be stored when closing the system | Scenario | TBD-S1 |
##  Low level Requirements:
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LR01 | New record shall be added by providing all the asked information and the id should be unique or else patient record should not be accepted. | HR01 | TBD-S1 |
| LR02 | Reading patient data should be possible in 2 ways, first being by searching by id of a patient and second by printing all the records available | HR02 | TBD-S1 |
| LR03 | While reading all the records, only 10 records per page should be visible and should add 10 more if user wants to see more | HR02 | FUTURE |
| LR04 | If user searches for an invalid ID "No Record Found" message should be displayed | HR02 | TBD-S1 |
| LR05 | User need to search by id for the pateint record to be updated, if no such record is available then "No Record Found" Message should be displayed | HR03 | TBD-S1 |
| LR06 | User need to search by id for the pateint record to be deleted, if no such record is available then "No Record Found" Message should be displayed | HR04 | TBD-S1 |
| LR05 | User shall be able to save the files, if file already exists then it should append to file and should not overwrite it and if file does not exists then it should create a new file | HR05 | TBD-S1 |
| LR06 | If opening the file fails, then the system shloud prompt the message "Unable to access file" and should not end the program execution | HR05, HR06, HR07, HR08 | TBD-S1 |
| LR07 | When user Log off the system, message shall be prompted asking the user to save new records to file before exiting or not | HR08 | TBD-S1 |
