# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Check if Linked List is created or not                        | (1). NULL Pointer (2). Unique id (3). First name (4). Last name (5). Height (6). Weight (7). Age  (8). Insurance Status (9). vaccine code| Pointer to head node | PASS | Requirement based|
|  H_01_01       |Check LL initialized from a file                           | (1). Head Pointer (2). File Pointer| LL should be initilized from a file|PASS|Scenario/Technical |
|  H_02   |Check Insertion of new data in list| (1). Head Pointer (2). Unique id (3). First name (4). Last name (5). Height (6). Weight (7). Age  (8). Insurance Status (9). vaccine code| SUCCESS |SUCCESS|Requirement based |
| H_02_01 | Check if during insertion id gets stored in file | (1). File name (2). file mode (3). File Pointer | SUCCESS | SUCCESS | Requirement based |
| H_02_02 | Check if during insertion no head exists | (1). File name (2). file mode (3). File Pointer | NO_HEAD_EXISTS | NO_HEAD_EXISTS | Technical |
| H_03 | Check if records are displayed properly | (1). Head Pointer | SUCCESS | SUCCESS | Requirement based |
| H_03_01 | Check if records in file are displayed properly | (1). File Pointer | SUCCESS | SUCCESS | Technical |
| H_04 | Check if search by Patient id is working correct | (1). Head pointer (2). Id (3). Result Pointer (4). Flag | SUCCESS | SUCCESS | Requirement based |
| H_05 | Check if record is updated properly | (1). Head pointer (2). Id (3). Field to be updated (4). Flag | SUCCESS | SUCCESS | Requirement based |
| H_05_01 | Check if record is also updated in File | (1). File Pointer (2). Id | SUCCESS | SUCCESS | Technical |
| H_06 | Deleting Record | (1). Head pointer (2). Id | Pointer to Head node| PASS| Requirement based |
| H_06_01 | If record is only present in List, then delete from List | (1). Head pointer (2). Id | Pointer to head node | PASS | Technical |
| H_06_02 | If record is only present in File, then delete from File | (1). File pointers (2). Id | SUCCESS | SUCCESS | Technical |
| H_06_03 | If record is deleted, then Index from Index File should also be deleted | (1). File pointers (2). Id | SUCCESS | SUCCESS | Technical |
| H_07 | When required list can be stored in file | (1). File pointers (2). Head Pointer (3). Flag| SUCCESS | SUCCESS | Requirement based |
| H_08 | When program shuts down records should be saved in File | (1). File pointers (2). Head Pointer| SUCCESS | SUCCESS | Requirement based |
| H_08_01 | When program Shuts down all allocated Memory Locations should be freed | (1). Head Pointer| No Memory Leaks | **FAIL** | Technical |



## Table no: Low level test plan

| **Test ID** | **HLT ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |H_02|During insertion check if ID is unique in INDEX.DAT file| (1). File Pointer (2). ID| SUCCESS | SUCCESS |Requirement based |
|  L_01_02    |H_02|Id f during insertion id alrady exists, do not allow insertion|  (1). File Pointer (2). ID| ID_ALREADY_EXISTS|ID_ALREADY_EXISTS|Scenario based|
|  L_03       |H_02,H_01,H_06,H_07|Check if file is properly opened during program execution| (1). File Name (2). File Mode (3). File Pointer|SUCCESS | SUCCESS |Technical|
|  L_04       |H_07,H_08|if data is loaded from file during startup then writing of file should begin from the start of file |(1). File pointers (2). Head Pointer (3). Flag |SUCCESS | SUCCESS |Technical|
|  L_05       |H_06|If there is only one node in list then deletion from beginning algorithm should work |(1). File pointers | SUCCESS | SUCCESS  |Technical|
|  L_06       |H_06|If first node is being deleted then deletion from beginning algorithm should work |(1). File pointers | SUCCESS | SUCCESS  |Technical|
