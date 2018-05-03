FIND_PACKAGE(Gettext REQUIRED)
FIND_PACKAGE(XGettext REQUIRED)

ADD_CUSTOM_TARGET(
      generate-pot
      ${GETTEXT_XGETTEXT_EXECUTABLE}
           -o ${CMAKE_CURRENT_SOURCE_DIR}/ibus-unikey.pot
           --keyword=_
           --keyword=N_
           --add-comments=TRANSLATORS:
           --directory=${CMAKE_SOURCE_DIR}
           --output-dir=${CMAKE_BINARY_DIR}
           --files-from=${CMAKE_CURRENT_SOURCE_DIR}/POTFILES.in
           --add-comments=TRANSLATORS:
           --copyright-holder=Ibus-Unikey's\ team
           --from-code=utf-8
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      COMMENT "Generating ibus-unikey.pot"
      VERBATIM
)

ADD_CUSTOM_TARGET(update-po)
ADD_DEPENDENCIES(update-po generate-pot)

ADD_CUSTOM_COMMAND(
    TARGET update-po
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "** Updating vi.po"
    COMMAND ${GETTEXT_MSGMERGE_EXECUTABLE}
         --quiet --update -m --backup=none -s
         ${CMAKE_CURRENT_SOURCE_DIR}/vi.po
         ${CMAKE_CURRENT_SOURCE_DIR}/ibus-unikey.pot
    VERBATIM
)