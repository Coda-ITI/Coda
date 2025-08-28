# Observation Service

## About 
This service is run on the IVI Node and is responsible for the following:
1. Receiving data/readings from Cluster Node through VSOMEIP and transfering it to the application layer through an AIDL contract.
2. Receiving event for changing theme through an AIDL contract and transfering it to Cluster Node through VSOMEIP.

## Sequence Diagram
<img width="763" height="685" alt="ObservationxCommManager" src="https://github.com/user-attachments/assets/689f2916-0f36-42b6-bae7-b9f6764dd63b" />
