/**
@file TagDescription.h

Created March 10th 2014
*/

#ifndef TAGDESCRIPTION_H
#define TAGDESCRIPTION_H

/**
 *	This enumeration contains all the possiblilites for tag description values
*/
enum Tag_Description
{
	UNKNOWN,
	ACCESSION_NUMBER,                                
	ACQUISITION_DATE,                               
	ACQUISITION_MATRIX,                              
	ACQUISITION_NUMBER,                              
	ACQUISITION_TIME,                              
	ANGIO_FLAG,                                      
	BITS_ALLOCATED,                                  
	BITS_STORED,                                     
	COLUMNS,                                         
	DB_DT,                                           
	DEVICE_SERIAL_NUMBER,                            
	ECHO_NUMBERS,                                  
	ECHO_TIME,                                       
	ECHO_TRAIN_LENGTH,                               
	FILE_META_INFORMATION_VERSION,                   
	FLIP_ANGLE,                                      
	FRAME_OF_REFERENCE_UID,                          
	GROUP_LENGTH,                                    
	HIGH_BIT,                                        
	IMAGE_COMMENTS,                                  
	IMAGE_DATE,                                      
	IMAGE_NUMBER,                                    
	IMAGE_ORIENTATION,                     
	IMAGE_POSITION,                      
	IMAGE_TIME,                               
	IMAGE_TYPE,                                      
	IMAGED_NUCLEUS,                                  
	IMAGING_FREQUENCY,                               
	IMPLEMENTATION_CLASS_UID,                        
	IMPLEMENTATION_VERSION_NAME,                     
	INSTITUTION_NAME,                      
	LARGEST_IMAGE_PIXEL_VALUE,                       
	LOSSY_IMAGE_COMPRESSION,                         
	LOSSY_IMAGE_COMPRESSION_RATIO,                 
	MAGNETIC_FIELD_STRENGTH,                   
	MANUFACTURER,                         
	MANUFACTURERS_MODEL_NAME,                  
	MEDIA_STORAGE_SOP_CLASS_UID,                     
	MEDIA_STORAGE_SOP_INSTANCE_UID,                  
	MODALITY,                                        
	MR_ACQUISITION_TYPE,                             
	NUMBER_OF_AVERAGES,                            
	NUMBER_OF_PHASE_ENCODING_STEPS,                  
	OPERATORS_NAME,                 
	PATIENT_ID,                                 
	PATIENT_POSITION,                                
	PATIENTS_AGE,                               
	PATIENTS_NAME,                                  
	PATIENTS_WEIGHT,                                
	PERCENT_PHASE_FIELD_OF_VIEW,                     
	PERCENT_SAMPLING,                    
	PERFORMED_PROCEDURE_STEP_DESCRIPTION,            
	PERFORMED_PROCEDURE_STEP_START_DATE,           
	PERFORMED_PROCEDURE_STEP_START_TIME,            
	PHASE_ENCODING_DIRECTION,                        
	PHOTOMETRIC_INTERPRETATION,                      
	PIXEL_BANDWIDTH,                        
	PIXEL_REPRESENTATION,                            
	PIXEL_SPACING,                            
	PROTOCOL_NAME,   
	REFERENCED_IMAGE_SEQUENCE,
	REFERENCED_PATIENT_SEQUENCE,                     
	//REFERENCED_SOP_CLASS_UID,                     
	//REFERENCED_SOP_INSTANCE_UID,                    
	REFERENCED_STUDY_COMPONENT_SEQUENCE,             
	REFERENCED_STUDY_SEQUENCE,            
	REFERRING_PHYSICIANS_NAME,                      
	REPETITION_TIME,                      
	REQUEST_ATTRIBUTES_SEQUENCE,                 
	REQUESTED_PROCEDURE_DESCRIPTION,                 
	//REQUESTED_PROCEDURE_ID,                
	REQUESTING_PHYSICIANN,                         
	ROWS,                           
	SAMPLES_PER_PIXEL,                               
	SAR,                              
	SCANNING_SEQUENCE,                               
	//SCHEDULED_PROCEDURE_STEP_DESCRIPTION,            
	//SCHEDULED_PROCEDURE_STEP_ID,           
	SCHEDULED_STUDY_LOCATION_AE_TITLES,            
	SCHEDULED_STUDY_START_DATE,           
	SCHEDULED_STUDY_START_TIME,                     
	SEQUENCE_NAME,                     
	SEQUENCE_VARIANT,                                
	SERIES_DATE,                               
	SERIES_DESCRIPTION,                              
	SERIES_INSTANCE_UID,                             
	SERIES_NUMBER,                             
	SERIES_TIME,                                   
	SLICE_LOCATION,                                  
	SLICE_THICKNESS,                                 
	SMALLEST_IMAGE_PIXEL_VALUE,                      
	SOFTWARE_VERSIONS,                     
	SOP_CLASS_UID,                            
	SOP_INSTANCE_UID,                                
	SOURCE_APPLICATION_ENTITY_TITLE,                 
	SPACING_BETWEEN_SLICES,                
	SPECIFIC_CHARACTER_SET,                         
	STATION_NAME,                         
	STUDY_COMMENTS,                                  
	STUDY_DATE,                                 
	STUDY_DESCRIPTION,                               
	STUDY_ID,                              
	STUDY_INSTANCE_UID,                              
	STUDY_STATUS_ID,                             
	STUDY_TIME,                                
	TRANSFER_SYNTAX_UID,                             
	TRANSMITTING_COLI,                            
	VARIABLE_FLIP_ANGLE_FLAG,                        
	WINDOW_CENTER,                       
	WINDOW_CENTER_AND_WIDTH_EXPLANATION,               
	WINDOW_WIDTH              
};

#endif /*TAGDESCRIPTION_H*/