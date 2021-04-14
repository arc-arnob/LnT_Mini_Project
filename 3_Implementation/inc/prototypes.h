
/**
 * @file prototypes.h
 * @author Arnob Chowdhury (https://github.com/arc-arnob)
 * @brief This program is for simulating data manipulation using Linked List
 * @version 0.1
 * @date 2021-04-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

#include<stdio.h>
//#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>


/**
 * @brief Error values for unit testing
 * 
 */
typedef enum error_t{
    ERROR_NULL_PTR = -2,
    SUCCESS = 0,
    START_EXISTS=1,
    NO_HEAD_EXIST=2,
    DATE_INCORRECT=3,
    INVALID_NAME=4,
    ID_EXISTS=5
}error_t;

/**
 * @brief Maps Vaccine codes to ints
 * 
 */
typedef enum vaccine{ 
    RED = 0,
    GREEN,
    YELLOW
}vaccine;

typedef enum insured{
    YES = 1,
    NO = 0
}insured;

/**
 * @brief Structure containing details about patient
 * 
 */
typedef struct patient{
    int uniq_id;
    char firstname[101];
    char lastname[101];
    char aadhar_num[21];
    float height;
    float weight;
    int age;
    char date_of_vaccine[13];
    insured insurance;
    vaccine shot;
    struct patient *next;
}patient;



/**
 * @brief Stores number of boxes with given vaccine
 * 
 */
typedef struct vaccine_data{
    int num; // Number of boxes with given code
    vaccine shot; // given code
}vaccine_data;




/**
 * @brief Create a linked list object
 * @param[in] box *  Pointer to head node
 * @param[in] int  id of patient
 * @param[in] char firstname of patient
 * @param[in] char lastname of patient
 * @param[in] char Aadhar Number of patient
 * @param[in] float height of patient
 * @param[in] float weight of patient
 * @param[in] int  age of patient
 * @param[in] Insurance  insurance status 0 for No 1 for Yes of patient
 * @param[in] Vaccine vaccine code of patient
 * @return patient * 
 */
patient *create_ll(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine);

/**
 * @brief display status of the patient records
 * @param[in]  patient * Pointer to start node
 * @return error_t 
 */
error_t display_ll(patient *);

/**
 * @brief Adds a node object at the end of the list
 * @param[in] box *  Pointer to head node
 * @param[in] int  id of patient
 * @param[in] char firstname of patient
 * @param[in] char lastname of patient
 * @param[in] char Aadhar Number of patient
 * @param[in] float height of patient
 * @param[in] float weight of patient
 * @param[in] int  age of patient
 * @param[in] Insurance  insurance status 0 for No 1 for Yes of patient
 * @param[in] Vaccine vaccine code of patient
 * @return error_t 
 */
error_t insert_end(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine);

/**
 * @brief finds a patient record by Id
 * @param[in]  patient * Pointer to start node
 * @param[out]  patient * Pointer to result node
 * @param[in]  int id to be found
 * @return error_t 
 */
error_t find_by_id(patient *, int, patient *, int *);

/**
 * @brief counts all patient by specific vaccine code
 * @param[in]  patient * Pointer to start node
 * @param[out]  color_data * Pointer to result enum
 * @param[in] Vaccine color
 * @return error_t 
 */
error_t count_by_vaccine(patient *, vaccine_data *, vaccine); //Count by insurance

/**
 * @brief Updates First Name of the patient
 * @param[in]  patient * Pointer to start node
 * @param[in]  int id to be updated
 * @param[in]  int attribute to be updated
 * @param[in]  int debug code 0 for production environment 1 for test environment
 * @return error_t 
 */
error_t update_record(patient *, int, int, int); // last int is 0 -> prod , 1 -> testing

/**
 * @brief deletes a patient record by id
 * @param[in]  patient * Pointer to start node
 * @param[in]  int id to be deleted
 * @return patient *
 */
patient *delete_patient(patient *, int);

/**
 * @brief Deletes record from file
 * @param[in]  int id to be deleted
 * @param[in]  FILE ** Pointer to file to be updated
 * @param[in]  FILE ** Pointer to temporary file 
 * @return error_t 
 */
error_t delete_rec_file(FILE **, FILE ** ,int);

/**
 * @brief Updates Index file
 * @param[in]  int id to be deleted
 * @param[in]  FILE ** Pointer to file to be updated
 * @param[in]  FILE ** Pointer to temporary file 
 * @return error_t 
 */
error_t delete_index_file(FILE **, FILE ** ,int);

/**
 * @brief Deletes all the nodes
 * @param[in]  patient * Pointer to start node
 * 
 */
void delete_all(patient *);

/**
 * @brief Deletes one node from the beginning
 * @param[in]  patient * Pointer to start node
 * @return patient * 
 */
patient *delete_beg(patient *);

/**
 * @brief This validates that patient id is unique
 * 
 * @param fptr 
 * @param int
 * @return error_t 
 */
error_t validate_id(FILE **fptr, int);

/**
 * @brief this file opens and read ids stored.
 * 
 * @param char File name
 * @param char File mode 
 * @param File File pointer 
 * @return error_t 
 */
error_t indexFile(char *addr, char *mode ,FILE **fptr);

/**
 * @brief this file opens records file.
 * 
 * @param char File name
 * @param char File mode 
 * @param File File pointer 
 * @return error_t 
 */
error_t openFile(char *addr, char *mode, FILE **fptr);

/**
 * @brief To save each record in file
 * 
 * @param patient * Pointer to head node
 * @param FILE * Pointer to file
 * @param int * Signifies how data should be stored in file, 1 means overwrite file 0 means append to file
 * @return error_t 
 */
error_t saveFile(patient *, FILE **, int *);

/**
 * @brief Reads file from file and prints
 * 
 * @param FILE file pointer
 * @return error_t 
 */
error_t readFile(FILE **fptr);

/**
 * @brief Loads data from file on program start up
 * @param patient * Pointer to head node
 * @param FILE file pointer
 * @return patient *
 */
patient* loadData(patient *, FILE **);

/**
 * @brief During update operation, automatically gets called to update data in file if exists.
 * @param FILE file pointer
 * @param int id to be updated
 * @return error_t 
 */
error_t update_data_file(FILE **, int);

#endif


