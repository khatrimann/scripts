import os
import io
import sys
import gzip
import shutil
import csv
from google.cloud import storage
from google.api_core.exceptions import BadRequest
from googleapiclient import http
from googleapiclient import discovery
import google.oauth2.credentials
import boto3
import pandas as pd


API_SCOPES = ['https://www.googleapis.com/auth/userinfo.email',
              'https://www.googleapis.com/auth/cloud-platform',
              'https://www.googleapis.com/auth/appengine.admin',
              'https://www.googleapis.com/auth/compute',
              'https://www.googleapis.com/auth/accounts.reauth']

LOCAL_PATH = "/tmp/"

s3 = boto3.client('s3')
S3_BUCKET= "lcs-testing"
bucket_name = "lcs-testing"
directory_name = "gcs_s3/" 
s3.put_object(Bucket=bucket_name, Key=(directory_name))

def load_user_credentials():
  credentials = google.oauth2.credentials.Credentials(None, refresh_token="1/tiltCTtfqUd5C48c3VloUzV1sWUIVsFtRj1P4knc4OGz-oQsQ1y5nQlg5cEdqzr7",
    token_uri="https://www.googleapis.com/oauth2/v4/token", client_id="638331008619-29do04jsn273r0da8boc997u56qvsrhb.apps.googleusercontent.com",
    client_secret="dBgBSzklTw1p5c0duj3xT48M", scopes=API_SCOPES)
  return credentials


def get_gcs_client():
    credentials = load_user_credentials()
    return storage.Client(project="dcm-fox", credentials=credentials)


def download_blob(storage_client, bucket, bucket_name, source_blob_name, destination_file_name):
    blob = bucket.blob(source_blob_name)
    blob.download_to_filename(destination_file_name)
    print('Blob {} downloaded to {}.'.format(
        source_blob_name,
        destination_file_name))



def list_blobs(storage_client, bucket_name, prefix):
    bucket = storage_client.get_bucket(bucket_name)

    blobs = bucket.list_blobs(prefix=prefix)

    for blob in blobs:
        download_blob(storage_client, bucket, bucket_name,blob.name,LOCAL_PATH+blob.name)
        fname = blob.name.split(".")
        fileGz = LOCAL_PATH+blob.name
        uploadPath = LOCAL_PATH+fname[0]+"."+fname[1]
        gzipExtract(fileGz,uploadPath)
        s3.upload_file( uploadPath, S3_BUCKET, directory_name + fname[0]+"."+fname[1])
        print("File successfully uploaded.")
        os.remove(fileGz)
        os.remove(uploadPath)


def gzipExtract(file_input, file_output):
    # with gzip.open(file_input) as f_in:
    #     datareader = csv.reader(io.TextIOWrapper(f_in, newline=""))
    #     for row in datareader:
    #       	if datareader.line_num == 2:
    #               with open(file_output, 'wb') as f_out:
    #                 shutil.copyfileobj(f_in, f_out)
    #                 print('GZip Extracted as {}.'.format(
    #                     file_output))    
    #                 return

   import csv

    try:
    read = csv.reader("./dcm_advertiser8412296_activity_20181129_20181130_052052_2023508019.csv")
    read.next()     # Skip the first 'title' row.
    for r in read:
        # Do something
    finally:
    # Close files and exit cleanly
    f.close()
        
        
if __name__ == "__main__":
    gcs_client = get_gcs_client()
    bucket_name = "dcdt_-dcm_account762302"

    try:
        gcs_client.get_bucket(bucket_name)
    except Exception as exception:
        print(exception)
    else:
        print("Bucket exists and we have access to it.")
    
    list_blobs(gcs_client, bucket_name, "dcm_advertiser8412296")