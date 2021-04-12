# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |Check if Linked List is created or not                        | (1). NULL Pointer (2). Unique id (3). First name (4). Last name (5). Height (6). Weight (7). Age  (8). Insurance Status (9). vaccine code|A linked list should be created| --TBD-- | Technical|
|  H_01_01       |Check LL initialized from a file                           | (1). Head Pointer (2). File Pointer| LL should be initilized from a file|--TBD--|Scenario/Technical |
|  H_02   |Check Insertion of new data in list| (1). Head Pointer (2). Unique id (3). First name (4). Last name (5). Height (6). Weight (7). Age  (8). Insurance Status (9). vaccine code| SUCCESS |-TBD-|Technical |
| H_02_01 | Check if during insertion id gets stored in file | (1). File name (2). file mode (3). File Pointer | SUCCESS | --TBD | Technical |
| H_03 | Check if records are displayed properly | (1). Head Pointer | SUCCESS | --TBD | Technical |
| H_03_01 | Check if records in file are displayed properly | (1). File Pointer | SUCCESS | --TBD | Technical |
| H_04 | Check if search by Patient id is working correct | (1). Head pointer (2). Id (3). Result Pointer (4). Flag | SUCCESS | --TBD | Technical |
| H_05 | Check if record is updated properly | (1). Head pointer (2). Id (3). Field to be updated (4). Flag | SUCCESS | --TBD | Technical |
| H_05_01 | Check if record is also updated in File | (1). File Pointer (2). Id | SUCCESS | --TBD | Technical |

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |--------------------------------------------------------------|  ------------|-------------|----------------|Requirement based |
|  L_02       |--------------------------------------------------------------|  ------------|-------------|----------------|Scenario based    |
|  L_03       |--------------------------------------------------------------|  ------------|-------------|----------------|Boundary based    |
