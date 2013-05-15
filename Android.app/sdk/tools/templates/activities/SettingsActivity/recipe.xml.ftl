<?xml version="1.0"?>
<recipe>
    <merge from="AndroidManifest.xml.ftl"
             to="${manifestOut}/AndroidManifest.xml" />

    <copy from="res/xml/pref_data_sync.xml"
            to="${resOut}/xml/pref_data_sync.xml" />
    <copy from="res/xml/pref_general.xml"
            to="${resOut}/xml/pref_general.xml" />
    <merge from="res/xml/pref_headers.xml.ftl"
             to="${resOut}/xml/pref_headers.xml" />
    <copy from="res/xml/pref_notification.xml"
            to="${resOut}/xml/pref_notification.xml" />

    <instantiate from="res/values/strings.xml.ftl"
                   to="${resOut}/values/strings_${simpleName}.xml" />

    <instantiate from="src/app_package/SettingsActivity.java.ftl"
                   to="${srcOut}/${activityClass}.java" />

    <open file="${srcOut}/${activityClass}.java" />
</recipe>
