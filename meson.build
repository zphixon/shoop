project('lol', 'c', default_options: ['c_std=c11'])

object_so = shared_library('object',
  'object.c',
  name_prefix: '',
)

dep = declare_dependency(link_with: object_so)

executable('main',
  sources: [
    'main.c',
    'object_maker.c',
  ],
  dependencies: [dep],
)
